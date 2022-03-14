#include "Vector2.h"
#include "Constants.h"

namespace mtn {
    Vector2::Vector2():x(0.0), y(0.0) {};
    Vector2::Vector2(float uX, float uY):x(uX), y(uY) {}
    Vector2::Vector2(const Vector2& v):x(v.x), y(v.y) {}
    Vector2::~Vector2() {}
    
    Vector2& Vector2::operator = (const Vector2& v) {
        x = v.x;
        y = v.y;
        
        return * this;
    }
    void Vector2::operator += (const Vector2& v) {
        x += v.x;
        y += v.y;
    }
    Vector2 Vector2::operator + (const Vector2& v) const {
        return Vector2(x + v.x, y + v.y);
    }
    void Vector2::operator -= (const Vector2& v) {
        x -= v.x;
        y -= v.y;
    }
    Vector2 Vector2::operator - (const Vector2& v) const {
        return Vector2(x - v.x, y - v.y);
    }
    void Vector2::operator *= (const float s) {
        x *= s;
        y *= s;
    }
    Vector2 Vector2::operator * (const float s) const {
        return Vector2(s * x, s * y);
    }
    void Vector2::operator /= (const float s) {
        x = x / s;
        y = y / s;
    }
    Vector2 Vector2::operator / (const float s) const {
        return Vector2(x / s, y / s);
    }
    float Vector2::operator * (const Vector2& v) const {
        return x * v.x + y * v.y;
    }    
    
    void Vector2::absolute() {
        x = std::abs(x);
        y = std::abs(y);
    }
}