#include <stdio.h>
#include <cmath>
#include <iostream>

#ifndef Vector3_hpp
#define Vector3_hpp

namespace mtn {
    class Vector3{
        private:
            
        public:
            float x;
            float y;
            float z;
            
            Vector3();
            Vector3(float uX,float uY,float uZ);
            Vector3(const Vector3& v);
            ~Vector3();
            
            Vector3& operator = (const Vector3& v);
            void operator += (const Vector3& v);
            Vector3 operator + (const Vector3& v)const;
            void operator -= (const Vector3& v);
            Vector3 operator - (const Vector3& v)const;
            void operator *= (const float s);
            Vector3 operator * (const float s)const;
            void operator /= (const float s);
            Vector3 operator / (const float s)const;
            float operator * (const Vector3& v) const;
            

            void operator %= (const Vector3& v);
            Vector3 operator % (const Vector3& v) const;
            

            float dot(const Vector3& v) const;
            Vector3 cross(const Vector3& v) const;
            float angle(const Vector3& v);
            void conjugate();
            void normalize();
            float magnitude();
            float magnitudeSquare();
            void zero();
            void absolute();
            Vector3 rotateVecAroundAngleAndAxis(float uNgl, Vector3& uAX);
            
            void show();
            void negate();
    };
}

#endif