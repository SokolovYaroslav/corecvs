#include <QFileDialog>

#include "cameraModelParametersControlWidget.h"
#include "ui_cameraModelParametersControlWidget.h"

#include "core/camerafixture/fixtureScene.h"

CameraModelParametersControlWidget::CameraModelParametersControlWidget(QWidget *parent) :
    ParametersControlWidgetBase(parent),
    ui(new Ui::CameraModelParametersControlWidget)
{
    ui->setupUi(this);

    ui->lensDistortionWidget->toggleAdvanced(false);


    QObject::connect(ui->cameraNameEdit      , SIGNAL(textChanged(QString)), this, SLOT(paramsChangedInUI()));
    QObject::connect(ui->lensDistortionWidget, SIGNAL(paramsChanged())     , this, SLOT(paramsChangedInUI()));
    QObject::connect(ui->extrinsicWorldWidget, SIGNAL(paramsChanged())     , this, SLOT(paramsChangedInUI()));

    QObject::connect(ui->spinBoxFocalX, SIGNAL(valueChanged(double)), this, SLOT(paramsChangedInUI()));
    QObject::connect(ui->spinBoxFocalY, SIGNAL(valueChanged(double)), this, SLOT(paramsChangedInUI()));

    QObject::connect(ui->spinBoxCx, SIGNAL(valueChanged(double)), this, SLOT(paramsChangedInUI()));
    QObject::connect(ui->spinBoxCy, SIGNAL(valueChanged(double)), this, SLOT(paramsChangedInUI()));

    QObject::connect(ui->spinBoxSkew, SIGNAL(valueChanged(double)), this, SLOT(paramsChangedInUI()));
//    writeUi();
    /* Addintional buttons */

    QObject::connect(ui->loadPushButton, SIGNAL(released()), this, SLOT(loadPressed()));
    QObject::connect(ui->savePushButton, SIGNAL(released()), this, SLOT(savePressed()));
    QObject::connect(ui->revertButton  , SIGNAL(released()), this, SLOT(revertPressed()));

    /* Extrinsics reset button */
    QObject::connect(ui->zeroExtrinsicsPushButton , SIGNAL(released()), this, SLOT( zeroPressed()));
    QObject::connect(ui->resetExtrinsicsPushButton, SIGNAL(released()), this, SLOT(resetPressed()));

    ui->extrinsicCamWidget->setEnabled(false);

}

CameraModelParametersControlWidget::~CameraModelParametersControlWidget()
{
    delete_safe(ui);
}

LensDistortionModelParameters CameraModelParametersControlWidget::lensDistortionParameters()
{
    LensDistortionModelParameters result;
    ui->lensDistortionWidget->getParameters(result);
    return result;
}

void CameraModelParametersControlWidget::setLensDistortionParameters(const LensDistortionModelParameters &params)
{
    ui->lensDistortionWidget->setParameters(params);
}

void CameraModelParametersControlWidget::loadParamWidget(WidgetLoader &loader)
{
    ui->lensDistortionWidget->loadParamWidget(loader);
   /**/
}


void CameraModelParametersControlWidget::saveParamWidget(WidgetSaver &saver)
{
    ui->lensDistortionWidget->saveParamWidget(saver);
    /**/
}

void CameraModelParametersControlWidget::loadPressed()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        "LOAD: Choose an camera config name",
        ".",
        "Text (*.json)"
    );
    if (!filename.isEmpty()) {
        emit loadRequest(filename);
    }
}

void CameraModelParametersControlWidget::savePressed()
{
    QString filename = QFileDialog::getSaveFileName(
        this,
        "SAVE: Choose an camera config name",
        ".",
        "Text (*.json)"
    );
    if (!filename.isEmpty()) {
        emit saveRequest(filename);
    }
}

void CameraModelParametersControlWidget::revertPressed()
{
//    qDebug() << "CameraModelParametersControlWidget::revertPressed(): pressed";
    setParameters(backup);
}

void CameraModelParametersControlWidget::zeroPressed()
{
    Affine3DQ zero = Affine3DQ::Identity();
    ui->extrinsicWorldWidget->setParameters(zero);
    emit paramsChanged();
}

void CameraModelParametersControlWidget::resetPressed()
{
    Affine3DQ zero = FixtureScene::DEFAULT_WORLD_TO_CAMERA.inverted();
    ui->extrinsicWorldWidget->setParameters(zero);
    emit paramsChanged();
}

void CameraModelParametersControlWidget::paramsChangedInUI()
{
//    qDebug() << "CameraModelParametersControlWidget::paramsChangedInUI(): pressed";
    ui->revertButton->setEnabled(true);
    emit paramsChanged();
}

/**/

void CameraModelParametersControlWidget::getParameters(CameraModel& params) const
{    
    ui->lensDistortionWidget->getParameters(params.distortion);

    params.nameId = ui->cameraNameEdit->text().toStdString();

    Affine3DQ location;
    ui->extrinsicWorldWidget->getParameters(location);
    params.setLocation(location);

    params.intrinsics.focal.x() = ui->spinBoxFocalX->value();
    params.intrinsics.focal.y() = ui->spinBoxFocalY->value();

    params.intrinsics.principal.x() = ui->spinBoxCx->value();
    params.intrinsics.principal.y() = ui->spinBoxCy->value();

    params.intrinsics.skew = ui->spinBoxSkew->value();
}

CameraModel *CameraModelParametersControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/
    CameraModel *result = new CameraModel();
    getParameters(*result);
    return result;
}

void CameraModelParametersControlWidget::setParameters(const CameraModel &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);

    ui->cameraNameEdit->setText(QString::fromStdString(input.nameId));
    ui->lensDistortionWidget->setParameters(input.distortion);

    ui->extrinsicWorldWidget->setParameters(input.getAffine());
    ui->extrinsicCamWidget->setParameters(FixtureScene::DEFAULT_WORLD_TO_CAMERA * input.getAffine());

    ui->spinBoxFocalX->setValue(input.intrinsics.fx());
    ui->spinBoxFocalY->setValue(input.intrinsics.fy());

    ui->spinBoxCx->setValue(input.intrinsics.cx());
    ui->spinBoxCy->setValue(input.intrinsics.cy());

    ui->spinBoxSkew->setValue(input.intrinsics.skew);

    ui->infoLabel->setText(QString("Size(xy):[%1 x %2] dist:[%3 x %4]")
                .arg(input.intrinsics.size.x()).arg(input.intrinsics.size.y())
                .arg(input.intrinsics.distortedSize.x()).arg(input.intrinsics.distortedSize.y()));


    blockSignals(wasBlocked);
    backup = input;
    ui->revertButton->setEnabled(false);

    emit paramsChanged();
}

void CameraModelParametersControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    CameraModel *inputCasted = static_cast<CameraModel *>(input);
    setParameters(*inputCasted);
}




FixtureCameraParametersControlWidget::FixtureCameraParametersControlWidget(QWidget *parent) :
    CameraModelParametersControlWidget(parent)
{
    QComboBox *prototypeBox = new QComboBox();
    prototypeBox->addItem("NULL");
    prototypeBox->addItem("Dummy");

    ui->mainLayout->addWidget(prototypeBox, 0, 0, 1, 1);
}
