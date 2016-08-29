/**
 * \file egomotionParametersControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "egomotionParametersControlWidget.h"
#include "ui_egomotionParametersControlWidget.h"
#include <memory>
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"


EgomotionParametersControlWidget::EgomotionParametersControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : ParametersControlWidgetBase(parent)
    , mUi(new Ui::EgomotionParametersControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->testSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->useOpenCVCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->selectorQualitySpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->selectorDistanceSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->selectorSizeSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->useHarrisSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->harrisKSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->kltSizeSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->cameraFocalSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->cameraPrincipalXSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->cameraPrincipalYSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
}

EgomotionParametersControlWidget::~EgomotionParametersControlWidget()
{

    delete mUi;
}

void EgomotionParametersControlWidget::loadParamWidget(WidgetLoader &loader)
{
    std::unique_ptr<EgomotionParameters> params(createParameters());
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
}

void EgomotionParametersControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    saver.saveParameters(*std::unique_ptr<EgomotionParameters>(createParameters()), rootPath);
}

void EgomotionParametersControlWidget::getParameters(EgomotionParameters& params) const
{
    params = *std::unique_ptr<EgomotionParameters>(createParameters());
}


EgomotionParameters *EgomotionParametersControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/


    return new EgomotionParameters(
          mUi->testSpinBox->value()
        , mUi->useOpenCVCheckBox->isChecked()
        , mUi->selectorQualitySpinBox->value()
        , mUi->selectorDistanceSpinBox->value()
        , mUi->selectorSizeSpinBox->value()
        , mUi->useHarrisSpinBox->value()
        , mUi->harrisKSpinBox->value()
        , mUi->kltSizeSpinBox->value()
        , mUi->cameraFocalSpinBox->value()
        , mUi->cameraPrincipalXSpinBox->value()
        , mUi->cameraPrincipalYSpinBox->value()
    );
}

void EgomotionParametersControlWidget::setParameters(const EgomotionParameters &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->testSpinBox->setValue(input.test());
    mUi->useOpenCVCheckBox->setChecked(input.useOpenCV());
    mUi->selectorQualitySpinBox->setValue(input.selectorQuality());
    mUi->selectorDistanceSpinBox->setValue(input.selectorDistance());
    mUi->selectorSizeSpinBox->setValue(input.selectorSize());
    mUi->useHarrisSpinBox->setValue(input.useHarris());
    mUi->harrisKSpinBox->setValue(input.harrisK());
    mUi->kltSizeSpinBox->setValue(input.kltSize());
    mUi->cameraFocalSpinBox->setValue(input.cameraFocal());
    mUi->cameraPrincipalXSpinBox->setValue(input.cameraPrincipalX());
    mUi->cameraPrincipalYSpinBox->setValue(input.cameraPrincipalY());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void EgomotionParametersControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    EgomotionParameters *inputCasted = static_cast<EgomotionParameters *>(input);
    setParameters(*inputCasted);
}
