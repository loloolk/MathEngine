#include "Quaternion.h"
#include "Vector3.h"
#include "Constants.h"

namespace mtn {
    Qnion::Qnion() {}
    Qnion::Qnion(float uS, Vector3& uV):s(uS), v(uV) {}
    Qnion::Qnion(const Qnion & val) {
        s = val.s;
        v = val.v;
    };
    Qnion::~Qnion() {}

    Qnion& Qnion::operator = (const Qnion& val) {
        s = val.s;
        v = val.v;
        
        return  * this;
    };
    void Qnion::operator += (const Qnion& q) {
        s += q.s;
        v += q.v;
    }
    Qnion Qnion::operator + (const Qnion& q) const {
        float scalar = s + q.s;
        Vector3 non = v + q.v;
        
        return Qnion(scalar, non);
    }
    void Qnion::operator -= (const Qnion& q) {
        s -= q.s;
        v -= q.v;
    }
    Qnion Qnion::operator-(const Qnion& q) const {
        float scalar = s - q.s;
        Vector3 non = v - q.v;
        
        return Qnion(scalar, non);
    }
    void Qnion::operator *= (const Qnion& q) {
        ( * this) = multiply(q);
    }
    Qnion Qnion::operator * (const Qnion& q) const {
        float scalar = s * q.s - v.dot(q.v);
        Vector3 non = q.v * s + v * q.s + v.cross(q.v);
        
        return Qnion(scalar, non);
    }
    Qnion Qnion::multiply(const Qnion& q) const {
        float scalar = s * q.s - v.dot(q.v);
        Vector3 non = q.v * s + v * q.s + v.cross(q.v);
        
        return Qnion(scalar, non);
    }
    void Qnion::operator *= (const float val) {
        s  *= val;
        v  *= val;
    }
    Qnion Qnion::operator * (const float val) const {
        float scalar = s * val;
        Vector3 non = v * val;
        
        return Qnion(scalar, non);
    }
    Qnion Qnion::operator * (const Vector3& uVal) const {
        float sPart = -(v.x * uVal.x +  v.y * uVal.y + v.z * uVal.z);
        float xPart = s * uVal.x + v.y * uVal.z - v.z * uVal.y;
        float yPart = s * uVal.y + v.z * uVal.x - v.x * uVal.z;
        float zPart = s * uVal.z + v.x * uVal.y - v.y * uVal.x;
        
        Vector3 vectorPart(xPart, yPart, zPart);
        Qnion result(sPart, vectorPart);
        
        return result;  
    }
    
    
    float Qnion::dot(Qnion& q) {
        return s * q.s + v.x * q.v.x + v.y * q.v.y + v.z * q.v.z;
    }
    float Qnion::norm() {
        float scalar = s * s;
        float non = v * v;
        
        return sqrt(scalar + non);
    }
    void Qnion::normalize() {
        if (norm() != 0) {
            float normval = 1/norm();
            
            s *= normval;
            v *= normval;
        }
    }
    Qnion Qnion::conjugate() {
        float scalar = s;
        Vector3 non = v * (-1);
        
        return Qnion(scalar, non);
    }
    Qnion Qnion::inverse() {
        float absoluteval = norm();
        absoluteval *= absoluteval;
        absoluteval = 1 / absoluteval;
        Qnion conjugateval = conjugate();
        
        float scalar = conjugateval.s * (absoluteval);
        Vector3 non = conjugateval.v * (absoluteval);
        
        return Qnion(scalar, non);
    }
    void Qnion::inverse(Qnion& q) {
        Qnion dummy = q.inverse();
        q = dummy;
    }
    void Qnion::convertToUnitNormQnion() {
        float angle = DegreesToRad(s);
        
        v.normalize();
        s = cosf(angle * 0.5);
        v = v * sinf(angle * 0.5);
    }
    Matrix3 Qnion::transformQnionToMatrix3n() {
        Matrix3 m;
        
        m.mData[0] = 2 * (s * s + v.x * v.x)-1;
        m.mData[3] = 2 * (v.x * v.y - s * v.z);
        m.mData[6] = 2 * (v.x * v.z + s * v.y);
        m.mData[1] = 2 * (v.x * v.y + s * v.z);
        m.mData[4] = 2 * (s * s + v.y * v.y)-1;
        m.mData[7] = 2 * (v.y * v.z - s * v.x);
        m.mData[2] = 2 * (v.x * v.z - s * v.y);
        m.mData[5] = 2 * (v.y * v.z + s * v.x);
        m.mData[8] = 2 * (s * s + v.z * v.z)-1;
        
        return m;
    }
    
    
    void Qnion::transformEulerAnglesToQnion(float x, float y,  float z) {
        x = DegreesToRad(x);
        y = DegreesToRad(y);
        z = DegreesToRad(z);
        
        x = x / 2;
        y = y / 2;
        z = z / 2;
        
        s = cos(z) * cos(y) * cos(x) + sin(z) * sin(y) * sin(x);
        v.x = cos(z) * cos(y) * sin(x) - sin(z) * sin(y) * cos(x);
        v.y = cos(z) * sin(y) * cos(x) + sin(z) * cos(y) * sin(x);
        v.z = sin(z) * cos(y) * cos(x) - cos(z) * sin(y) * sin(x);
    }
    Vector3 Qnion::transformQnionToEulerAngles() {
        float x = 0.0;
        float y = 0.0;
        float z = 0.0;
        float test = 2 * (v.x * v.z - s * v.y);
        
        if (test != 1 && test != -1) {
            x = atan2(v.y * v.z + s * v.x,  0.5 - (v.x * v.x + v.y * v.y));
            y = asin(-2 * (v.x * v.z - s * v.y));
            z = atan2(v.x * v.y + s * v.z,  0.5 - (v.y * v.y + v.z * v.z));
        }
        else if (test == 1) {
            z = atan2(v.x * v.y + s * v.z,  0.5 - (v.y * v.y + v.z * v.z));
            y = -M_PI / 2.0;
            x = -z + atan2(v.x * v.y-s * v.z,  v.x * v.z + s * v.y);
            
        }
        else if(test == -1) {
            
            z = atan2(v.x * v.y + s * v.z,  0.5 - (v.y * v.y + v.z * v.z));
            y = M_PI / 2.0;
            x = z + atan2(v.x * v.y-s * v.z,  v.x * v.z + s * v.y); 
        }
        
        x = RadToDegrees(x);
        y = RadToDegrees(y);
        z = RadToDegrees(z);
        Vector3 euler(x, y, z);
        
        return euler;
    }
    void Qnion::transformMatrix3nToQnion(Matrix3 &uMatrix) {
        float trace = uMatrix.mData[0] + uMatrix.mData[4] + uMatrix.mData[8];
        
        if (trace > 0) {
            s = 0.5 * sqrt(1 + trace);
            float S = 0.25 /s ;
            
            v.x = S * (uMatrix.mData[5] - uMatrix.mData[7]);
            v.y = S * (uMatrix.mData[6] - uMatrix.mData[2]);
            v.z = S * (uMatrix.mData[1] - uMatrix.mData[3]);
        }
        else if(uMatrix.mData[0] > uMatrix.mData[4] && uMatrix.mData[0] > uMatrix.mData[8]) {
            v.x = 0.5 * sqrt(1 + uMatrix.mData[0] - uMatrix.mData[4] - uMatrix.mData[8]);
            float X = 0.25 / v.x;
            
            v.y = X * (uMatrix.mData[3] + uMatrix.mData[1]);
            v.z = X * (uMatrix.mData[6] + uMatrix.mData[2]);
            s = X * (uMatrix.mData[5] - uMatrix.mData[7]);
        }
        else if(uMatrix.mData[4] > uMatrix.mData[8]) {
            v.y = 0.5 * sqrt(1 - uMatrix.mData[0] + uMatrix.mData[4] - uMatrix.mData[8]);
            float Y = 0.25 / v.y;
            v.x = Y * (uMatrix.mData[3] + uMatrix.mData[1]);
            v.z = Y * (uMatrix.mData[7] + uMatrix.mData[5]);
            s = Y * (uMatrix.mData[6] - uMatrix.mData[2]);
            
        }
        else{
            v.z = 0.5 * sqrt(1-uMatrix.mData[0] - uMatrix.mData[4] + uMatrix.mData[8]);
            float Z = 0.25 / v.z;
            v.x = Z * (uMatrix.mData[6] + uMatrix.mData[2]);
            v.y = Z * (uMatrix.mData[7] + uMatrix.mData[5]);
            s = Z * (uMatrix.mData[1] - uMatrix.mData[3]);
        }
    }
    
    
    void Qnion::show() {
        float x = v.x;
        float y = v.y;
        float z = v.z;
        
        std::cout << "(" << s << ", " << x << ", " << y << ", " << z << ")" << std::endl;
    }
}