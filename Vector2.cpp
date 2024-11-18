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
    bool Vector2::operator == (const Vector2& v) {
        return (x == v.x && y == v.y);   
    }
    std::ostream& operator <<(std::ostream& os, const mtn::Vector2& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
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
    float Vector2::dot(Vector2 a, Vector2 b) {
        return a.x * b.x + a.y * b.y;
    }


    /*Vector2 halfway(const line& l) {
        return mtn::Vector2((l.start.x + l.end.x) / 2, (l.start.y + l.end.y) / 2);
    }*/
}