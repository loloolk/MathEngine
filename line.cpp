#include "line.h"

namespace mtn {
    line::line() {
        start = Vector2(0.0, 0.0);
        end = Vector2(0.0, 0.0);
    }
    line::line(Vector2 s, Vector2 e) {
        start = s;
        end = e;
    }
    line::line(const line& l) {
        start = l.start;
        end = l.end;
    }
    line::~line() {}
    //test
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
}