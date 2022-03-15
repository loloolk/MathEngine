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


    line::line():start(0.0, 0.0), end(0.0, 0.0) {}
    line::line(Vector2 s, Vector2 e):start(s), end(e) {}
    line::line(const line& l):start(l.start), end(l.end) {}
    line::~line() {}

    line& line::operator = (const line& l) {
        start = l.start;
        end = l.end;
        
        return * this;
    }
    void line::operator += (const Vector2& v) {
        start += v;
        end += v;
    }
    line line::operator + (const Vector2& v) const {
        return line(start + v, end + v);
    }
    void line::operator -= (const Vector2& v) {
        start -= v;
        end -= v;
    }
    line line::operator - (const Vector2& v) const {
        return line(start - v, end - v);
    }

    Vector2& halfway(const line& l) {
        return mtn::Vector2((l.start.x + l.end.x) / 2, (l.start.y + l.end.y) / 2);
    }

}