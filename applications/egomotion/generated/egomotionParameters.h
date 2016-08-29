#ifndef EGOMOTION_PARAMETERS_H_
#define EGOMOTION_PARAMETERS_H_
/**
 * \file egomotionParameters.h
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "reflection.h"
#include "defaultSetter.h"
#include "printerVisitor.h"

/*
 *  Embed includes.
 */
/*
 *  Additional includes for Composite Types.
 */

using namespace corecvs;

/*
 *  Additional includes for Pointer Types.
 */

namespace corecvs {
}
/*
 *  Additional includes for enum section.
 */

/**
 * \brief Egomotion Parameters 
 * Egomotion Parameters 
 **/
class EgomotionParameters : public BaseReflection<EgomotionParameters>
{
public:
    enum FieldId {
        TEST_ID,
        USEOPENCV_ID,
        SELECTORQUALITY_ID,
        SELECTORDISTANCE_ID,
        SELECTORSIZE_ID,
        USEHARRIS_ID,
        HARRISK_ID,
        KLTSIZE_ID,
        CAMERAFOCAL_ID,
        CAMERAPRINCIPALX_ID,
        CAMERAPRINCIPALY_ID,
        EGOMOTION_PARAMETERS_FIELD_ID_NUM
    };

    /** Section with variables */

    /** 
     * \brief test 
     * test 
     */
    double mTest;

    /** 
     * \brief useOpenCV 
     * useOpenCV 
     */
    bool mUseOpenCV;

    /** 
     * \brief selectorQuality 
     * selectorQuality 
     */
    double mSelectorQuality;

    /** 
     * \brief selectorDistance 
     * selectorDistance 
     */
    double mSelectorDistance;

    /** 
     * \brief selectorSize 
     * selectorSize 
     */
    int mSelectorSize;

    /** 
     * \brief useHarris 
     * useHarris 
     */
    int mUseHarris;

    /** 
     * \brief harrisK 
     * harrisK 
     */
    double mHarrisK;

    /** 
     * \brief kltSize 
     * kltSize 
     */
    int mKltSize;

    /** 
     * \brief cameraFocal 
     * cameraFocal 
     */
    double mCameraFocal;

    /** 
     * \brief cameraPrincipalX 
     * cameraPrincipalX 
     */
    double mCameraPrincipalX;

    /** 
     * \brief cameraPrincipalY 
     * cameraPrincipalY 
     */
    double mCameraPrincipalY;

    /** Static fields init function, this is used for "dynamic" field initialization */ 
    static int staticInit();

    /** Section with getters */
    const void *getPtrById(int fieldId) const
    {
        return (const unsigned char *)(this) + fields()[fieldId]->offset;
    }
    double test() const
    {
        return mTest;
    }

    bool useOpenCV() const
    {
        return mUseOpenCV;
    }

    double selectorQuality() const
    {
        return mSelectorQuality;
    }

    double selectorDistance() const
    {
        return mSelectorDistance;
    }

    int selectorSize() const
    {
        return mSelectorSize;
    }

    int useHarris() const
    {
        return mUseHarris;
    }

    double harrisK() const
    {
        return mHarrisK;
    }

    int kltSize() const
    {
        return mKltSize;
    }

    double cameraFocal() const
    {
        return mCameraFocal;
    }

    double cameraPrincipalX() const
    {
        return mCameraPrincipalX;
    }

    double cameraPrincipalY() const
    {
        return mCameraPrincipalY;
    }

    /* Section with setters */
    void setTest(double test)
    {
        mTest = test;
    }

    void setUseOpenCV(bool useOpenCV)
    {
        mUseOpenCV = useOpenCV;
    }

    void setSelectorQuality(double selectorQuality)
    {
        mSelectorQuality = selectorQuality;
    }

    void setSelectorDistance(double selectorDistance)
    {
        mSelectorDistance = selectorDistance;
    }

    void setSelectorSize(int selectorSize)
    {
        mSelectorSize = selectorSize;
    }

    void setUseHarris(int useHarris)
    {
        mUseHarris = useHarris;
    }

    void setHarrisK(double harrisK)
    {
        mHarrisK = harrisK;
    }

    void setKltSize(int kltSize)
    {
        mKltSize = kltSize;
    }

    void setCameraFocal(double cameraFocal)
    {
        mCameraFocal = cameraFocal;
    }

    void setCameraPrincipalX(double cameraPrincipalX)
    {
        mCameraPrincipalX = cameraPrincipalX;
    }

    void setCameraPrincipalY(double cameraPrincipalY)
    {
        mCameraPrincipalY = cameraPrincipalY;
    }

    /* Section with embedded classes */
    /* visitor pattern - http://en.wikipedia.org/wiki/Visitor_pattern */
template<class VisitorType>
    void accept(VisitorType &visitor)
    {
        visitor.visit(mTest,                      static_cast<const DoubleField *>  (fields()[TEST_ID]));
        visitor.visit(mUseOpenCV,                 static_cast<const BoolField *>    (fields()[USEOPENCV_ID]));
        visitor.visit(mSelectorQuality,           static_cast<const DoubleField *>  (fields()[SELECTORQUALITY_ID]));
        visitor.visit(mSelectorDistance,          static_cast<const DoubleField *>  (fields()[SELECTORDISTANCE_ID]));
        visitor.visit(mSelectorSize,              static_cast<const IntField *>     (fields()[SELECTORSIZE_ID]));
        visitor.visit(mUseHarris,                 static_cast<const IntField *>     (fields()[USEHARRIS_ID]));
        visitor.visit(mHarrisK,                   static_cast<const DoubleField *>  (fields()[HARRISK_ID]));
        visitor.visit(mKltSize,                   static_cast<const IntField *>     (fields()[KLTSIZE_ID]));
        visitor.visit(mCameraFocal,               static_cast<const DoubleField *>  (fields()[CAMERAFOCAL_ID]));
        visitor.visit(mCameraPrincipalX,          static_cast<const DoubleField *>  (fields()[CAMERAPRINCIPALX_ID]));
        visitor.visit(mCameraPrincipalY,          static_cast<const DoubleField *>  (fields()[CAMERAPRINCIPALY_ID]));
    }

    EgomotionParameters()
    {
        DefaultSetter setter;
        accept(setter);
    }

    EgomotionParameters(
          double test
        , bool useOpenCV
        , double selectorQuality
        , double selectorDistance
        , int selectorSize
        , int useHarris
        , double harrisK
        , int kltSize
        , double cameraFocal
        , double cameraPrincipalX
        , double cameraPrincipalY
    )
    {
        mTest = test;
        mUseOpenCV = useOpenCV;
        mSelectorQuality = selectorQuality;
        mSelectorDistance = selectorDistance;
        mSelectorSize = selectorSize;
        mUseHarris = useHarris;
        mHarrisK = harrisK;
        mKltSize = kltSize;
        mCameraFocal = cameraFocal;
        mCameraPrincipalX = cameraPrincipalX;
        mCameraPrincipalY = cameraPrincipalY;
    }

    friend ostream& operator << (ostream &out, EgomotionParameters &toSave)
    {
        PrinterVisitor printer(out);
        toSave.accept<PrinterVisitor>(printer);
        return out;
    }

    void print ()
    {
        cout << *this;
    }
};
#endif  //EGOMOTION_PARAMETERS_H_
