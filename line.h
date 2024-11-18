#include "Vector2.h"

namespace mtn {
    class line {
        public:
            Vector2 start;
            Vector2 end;

            line();
            line(Vector2 s, Vector2 e);
            line(const line& l);
            ~line();

            line& operator = (const line& l);
            void operator += (const Vector2& v);
            line operator + (const Vector2& v)const;
            void operator -= (const Vector2& v);
            line operator - (const Vector2& v)const;
    };
}