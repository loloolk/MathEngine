#include <stdio.h>
#include <iostream>
#include "Vector3.h"

#ifndef Matrix3_
#define Matrix3_


namespace mtn {
    class Matrix3{
    private:
        
    public:
        float mData[9]={0.0};

        Matrix3();
        Matrix3(float m0,float m3,float m6,float m1,float m4,float m7,float m2,float m5,float m8);
        Matrix3& operator = (const Matrix3& value);
        ~Matrix3();
        
        Matrix3 operator + (const Matrix3 &m) const;
        void operator += (const Matrix3 &m);
        Matrix3 operator * (const float s) const;
        void operator *= (const float s);
        Vector3 operator * (const Vector3 & v) const;
        Vector3 transformVectorByMatrix(const Vector3& v) const;
        Matrix3 operator * (const Matrix3& m) const;
        void operator *= (const Matrix3& m);
        
        void setMatrixAsIdentityMatrix();
        void setMatrixAsInverseOfGivenMatrix(const Matrix3& m);
        Matrix3 getInverseOfMatrix() const;
        void invertMatrix();
        float getMatrixDeterminant() const;
        void setMatrixAsTransposeOfGivenMatrix(const Matrix3& m);
        Matrix3 getTransposeOfMatrix() const;
        void invertAndTransposeMatrix();

        
        void turnMatAboutXAxisByAngle(float uNgl);
        void turnMatAboutYAxisByAngle(float uNgl);
        void turnMatAboutZAxisByAngle(float uNgl);
        
        void transformMatAboutXAxisByAngle(float uNgl);
        void transformMatAboutYAxisByAngle(float uNgl);
        void transformMatAboutZAxisByAngle(float uNgl);
        
    
        void show();
    };
}

#endif