#include <stdio.h>
#include "Vector3.h"
#include "Matrix3.h"

#ifndef Qnion_
#define Qnion_

namespace mtn {
    
    class Qnion{
        
    public:
        float s;
        Vector3 v;
        
        Qnion();
        Qnion(float uS, Vector3& uV);
        Qnion(const Qnion & val);
        ~Qnion();
        
        inline Qnion& operator = (const Qnion& val);
        
        void operator += (const Qnion& q);
        Qnion operator + (const Qnion& q) const;
        void operator -= (const Qnion& q);
        Qnion operator - (const Qnion& q) const;
        void operator *= (const Qnion& q);
        Qnion operator * (const Qnion& q) const;
        void operator *= (const float val);
        Qnion operator * (const float val) const;
        Qnion operator * (const Vector3& val) const;
        
        Qnion multiply(const Qnion& q)const;
        float dot(Qnion& q);;
        float norm();
        
        void normalize();
        void convertToUnitNormQnion();
        Qnion conjugate();
        Qnion inverse();
        
        void inverse(Qnion& q);
        Matrix3 transformQnionToMatrix3n();
        void transformEulerAnglesToQnion(float x,float y, float z);
        Vector3 transformQnionToEulerAngles();
        void transformMatrix3nToQnion(Matrix3 &uMatrix);
        void show();
    };
}

#endif