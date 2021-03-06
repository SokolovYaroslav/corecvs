/**
 * \file lensDistortionModelParametersBase.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include <vector>
#include <stddef.h>
#include "lensDistortionModelParametersBase.h"

/**
 *  Looks extremely unsafe because it depends on the order of static initialization.
 *  Should check standard if this is ok
 *
 *  Also it's not clear why removing "= Reflection()" breaks the code;
 **/

namespace corecvs {
template<>
Reflection BaseReflection<LensDistortionModelParametersBase>::reflection = Reflection();
template<>
int BaseReflection<LensDistortionModelParametersBase>::dummy = LensDistortionModelParametersBase::staticInit();
} // namespace corecvs 

SUPPRESS_OFFSET_WARNING_BEGIN


using namespace corecvs;

int LensDistortionModelParametersBase::staticInit()
{

    ReflectionNaming &nameing = naming();
    nameing = ReflectionNaming(
        "Lens Distortion Model Parameters Base",
        "Lens Distortion Model Parameters",
        ""
    );

     getReflection()->objectSize = sizeof(LensDistortionModelParametersBase);
     

    DoubleField* field0 = new DoubleField
        (
          LensDistortionModelParametersBase::PRINCIPALX_ID,
          offsetof(LensDistortionModelParametersBase, mPrincipalX),
          240,
          "principalX",
          "principalX",
          "The center of the distortion \f$x_c\f$"
        );
    field0->widgetHint=BaseField::SPIN_BOX;
    field0->precision=2;
    fields().push_back(field0);
    /*  */ 
    DoubleField* field1 = new DoubleField
        (
          LensDistortionModelParametersBase::PRINCIPALY_ID,
          offsetof(LensDistortionModelParametersBase, mPrincipalY),
          320,
          "principalY",
          "principalY",
          "The center of the distortion \f$y_c\f$"
        );
    field1->widgetHint=BaseField::SPIN_BOX;
    field1->precision=2;
    fields().push_back(field1);
    /*  */ 
    DoubleField* field2 = new DoubleField
        (
          LensDistortionModelParametersBase::TANGENTIALX_ID,
          offsetof(LensDistortionModelParametersBase, mTangentialX),
          0,
          "tangentialX",
          "tangentialX",
          "First tangent correction coefficient - \f$p_1\f$"
        );
    field2->widgetHint=BaseField::SPIN_BOX;
    field2->precision=2;
    fields().push_back(field2);
    /*  */ 
    DoubleField* field3 = new DoubleField
        (
          LensDistortionModelParametersBase::TANGENTIALY_ID,
          offsetof(LensDistortionModelParametersBase, mTangentialY),
          0,
          "tangentialY",
          "tangentialY",
          "Second tangent correction coefficient - \f$p_2\f$"
        );
    field3->widgetHint=BaseField::SPIN_BOX;
    field3->precision=2;
    fields().push_back(field3);
    /*  */ 
    double mKoeff_dv[] = {0,0,0,0,0,0};
    DoubleVectorField* field4 = new DoubleVectorField
        (
          LensDistortionModelParametersBase::KOEFF_ID,
          offsetof(LensDistortionModelParametersBase, mKoeff),
          vector<double>(mKoeff_dv, mKoeff_dv + 6),
          6,
          "koeff",
          "koeff",
          "Polynom to describe radial correction"
        );
    field4->precision=2;
    fields().push_back(field4);
    /*  */ 
    DoubleField* field5 = new DoubleField
        (
          LensDistortionModelParametersBase::ASPECT_ID,
          offsetof(LensDistortionModelParametersBase, mAspect),
          1,
          "aspect",
          "aspect",
          "aspect"
        );
    field5->widgetHint=BaseField::SPIN_BOX;
    field5->precision=2;
    fields().push_back(field5);
    /*  */ 
    DoubleField* field6 = new DoubleField
        (
          LensDistortionModelParametersBase::SCALE_ID,
          offsetof(LensDistortionModelParametersBase, mScale),
          1,
          "scale",
          "scale",
          "scale"
        );
    field6->widgetHint=BaseField::SPIN_BOX;
    field6->precision=2;
    fields().push_back(field6);
    /*  */ 
    DoubleField* field7 = new DoubleField
        (
          LensDistortionModelParametersBase::NORMALIZING_FOCAL_ID,
          offsetof(LensDistortionModelParametersBase, mNormalizingFocal),
          1,
          "Normalizing Focal",
          "Normalizing Focal",
          "Normalizing Focal"
        );
    field7->widgetHint=BaseField::SPIN_BOX;
    field7->precision=2;
    fields().push_back(field7);
    /*  */ 
    DoubleField* field8 = new DoubleField
        (
          LensDistortionModelParametersBase::SHIFT_X_ID,
          offsetof(LensDistortionModelParametersBase, mShiftX),
          0,
          "shift X",
          "shift X",
          "Additional shift \f$x_s\f$"
        );
    field8->widgetHint=BaseField::SPIN_BOX;
    field8->precision=2;
    fields().push_back(field8);
    /*  */ 
    DoubleField* field9 = new DoubleField
        (
          LensDistortionModelParametersBase::SHIFT_Y_ID,
          offsetof(LensDistortionModelParametersBase, mShiftY),
          0,
          "shift Y",
          "shift Y",
          "Additional shift \f$y_s\f$"
        );
    field9->widgetHint=BaseField::SPIN_BOX;
    field9->precision=2;
    fields().push_back(field9);
    /*  */ 
    BoolField* field10 = new BoolField
        (
          LensDistortionModelParametersBase::MAP_FORWARD_ID,
          offsetof(LensDistortionModelParametersBase, mMapForward),
          false,
          "Map Forward",
          "Map Forward",
          "This one is used to identify map direction, true if undistorted->distorted"
        );
    field10->widgetHint=BaseField::CHECK_BOX;
    fields().push_back(field10);
    /*  */ 
    ReflectionDirectory &directory = *ReflectionDirectoryHolder::getReflectionDirectory();
    directory[std::string("Lens Distortion Model Parameters Base")]= &reflection;
   return 0;
}
int LensDistortionModelParametersBase::relinkCompositeFields()
{
   return 0;
}

SUPPRESS_OFFSET_WARNING_END


