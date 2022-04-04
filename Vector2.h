#include <stdio.h>
#include <cmath>
#include <iostream>

#ifndef Vector2_hpp
#define Vector2_hpp

namespace mtn {
    class Vector2 {
        public:
            float x;
            float y;
            
            Vector2();
            Vector2(float uX,float uY);
            Vector2(const Vector2& v);
            ~Vector2();
            
            Vector2& operator = (const Vector2& v);
            bool operator == (const Vector2& v);
            friend std::ostream& operator<<(std::ostream& os, const mtn::Vector2& v);
            void operator += (const Vector2& v);
            Vector2 operator + (const Vector2& v)const;
            void operator -= (const Vector2& v);
            Vector2 operator - (const Vector2& v)const;
            void operator *= (const float s);
            Vector2 operator * (const float s)const;
            void operator /= (const float s);
            Vector2 operator / (const float s)const;
            float operator * (const Vector2& v) const;

            void absolute();
            float dot(Vector2 a, Vector2 b);
    };
}

#endif