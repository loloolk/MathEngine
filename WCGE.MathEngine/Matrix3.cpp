#include "Matrix3.h"
#include "Constants.h"

namespace mtn {
    
    Matrix3::Matrix3() {
        for (int i = 0; i < 9; i++) {
            mData[i] = 0.0f;
        }
        
        mData[0] = mData[4] = mData[8] = 1.0f;
    }; 
    Matrix3::Matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8) {
        mData[0]  =  m0;
        mData[3]  =  m3;
        mData[6]  =  m6;
        mData[1]  =  m1;
        mData[4]  =  m4;
        mData[7]  =  m7;
        mData[2]  =  m2;
        mData[5]  =  m5;
        mData[8]  =  m8;
    };
    Matrix3& Matrix3::operator  =  (const Matrix3& value) {
        for (int i = 0; i < 9; i++) {
            mData[i] = value.mData[i];
        }
        return *this;
    };
    Matrix3::~Matrix3() {}  
    
    Matrix3 Matrix3::operator + (const Matrix3 &m) const {
        
        Matrix3 n;
        
        n.mData[0] = mData[0] + m.mData[0];
        n.mData[3] = mData[3] + m.mData[3];
        n.mData[6] = mData[6] + m.mData[6];
        
        n.mData[1] = mData[1] + m.mData[1];
        n.mData[4] = mData[4] + m.mData[4];
        n.mData[7] = mData[7] + m.mData[7];
        
        n.mData[2] = mData[2] + m.mData[2];
        n.mData[5] = mData[5] + m.mData[5];
        n.mData[8] = mData[8] + m.mData[8];
        
        return n;
    } 
    void Matrix3::operator += (const Matrix3 &m) {
        mData[0] += m.mData[0];
        mData[3] += m.mData[3];
        mData[6] += m.mData[6];
        mData[1] += m.mData[1];
        mData[4] += m.mData[4];
        mData[7] += m.mData[7];
        mData[2] += m.mData[2];
        mData[5] += m.mData[5];
        mData[8] += m.mData[8];
    }
    Matrix3 Matrix3::operator * (const Matrix3& m) const {
        return Matrix3(mData[0] * m.mData[0] +  mData[3] * m.mData[1] + mData[6] * m.mData[2], 
                       mData[0] * m.mData[3] +  mData[3] * m.mData[4] + mData[6] * m.mData[5], 
                       mData[0] * m.mData[6] +  mData[3] * m.mData[7] + mData[6] * m.mData[8], 
                       mData[1] * m.mData[0] +  mData[4] * m.mData[1] + mData[7] * m.mData[2], 
                       mData[1] * m.mData[3] +  mData[4] * m.mData[4] + mData[7] * m.mData[5], 
                       mData[1] * m.mData[6] +  mData[4] * m.mData[7] + mData[7] * m.mData[8], 
                       mData[2] * m.mData[0] +  mData[5] * m.mData[1] + mData[8] * m.mData[2], 
                       mData[2] * m.mData[3] +  mData[5] * m.mData[4] + mData[8] * m.mData[5], 
                       mData[2] * m.mData[6] +  mData[5] * m.mData[7] + mData[8] * m.mData[8]);
    }
    void Matrix3::operator *= (const Matrix3& m) {float t1;
        float t2;
        float t3;
        
        t1 = mData[0] * m.mData[0] +  mData[3] * m.mData[1] + mData[6] * m.mData[2];
        t2 = mData[0] * m.mData[3] +  mData[3] * m.mData[4] + mData[6] * m.mData[5];
        t3 = mData[0] * m.mData[6] +  mData[3] * m.mData[7] + mData[6] * m.mData[8];
        
        mData[0] = t1;
        mData[3] = t2;
        mData[6] = t3;
        
        t1 = mData[1] * m.mData[0] +  mData[4] * m.mData[1] + mData[7] * m.mData[2];
        t2 = mData[1] * m.mData[3] +  mData[4] * m.mData[4] + mData[7] * m.mData[5];
        t3 = mData[1] * m.mData[6] +  mData[4] * m.mData[7] + mData[7] * m.mData[8];
        
        mData[1] = t1;
        mData[4] = t2;
        mData[7] = t3;
        
        
        t1 = mData[2] * m.mData[0] +  mData[5] * m.mData[1] + mData[8] * m.mData[2];
        t2 = mData[2] * m.mData[3] +  mData[5] * m.mData[4] + mData[8] * m.mData[5];
        t3 = mData[2] * m.mData[6] +  mData[5] * m.mData[7] + mData[8] * m.mData[8];
        
        mData[2] = t1;
        mData[5] = t2;
        mData[8] = t3;
    }
    Matrix3 Matrix3::operator * (const float s) const {
        Matrix3 n;
        
        n.mData[0] = mData[0] * s;
        n.mData[3] = mData[3] * s;
        n.mData[6] = mData[6] * s;
        n.mData[1] = mData[1] * s;
        n.mData[4] = mData[4] * s;
        n.mData[7] = mData[7] * s;
        n.mData[2] = mData[2] * s;
        n.mData[5] = mData[5] * s;
        n.mData[8] = mData[8] * s;
        
        return n;
    }
    void Matrix3::operator *= (const float s) {
        mData[0] *= s;
        mData[3] *= s;
        mData[6] *= s;
        mData[1] *= s;
        mData[4] *= s;
        mData[7] *= s;
        mData[2] *= s;
        mData[5] *= s;
        mData[8] *= s;
    }
    Vector3 Matrix3::operator * (const Vector3 & v) const {
        return Vector3(mData[0] * v.x + mData[3] * v.y + mData[6] * v.z, 
                       mData[1] * v.x + mData[4] * v.y + mData[7] * v.z, 
                       mData[2] * v.x + mData[5] * v.y + mData[8] * v.z);
    }


    Vector3 Matrix3::transformVectorByMatrix(const Vector3& v) const {
        return (*this) * v;
    }    
    void Matrix3::setMatrixAsIdentityMatrix() {
        for (int i = 0; i < 9; i++) {
            mData[i] = 0.0f;
        }
        mData[0] = mData[4] = mData[8] = 1.0f;
    }
    void Matrix3::setMatrixAsInverseOfGivenMatrix(const Matrix3& m) {
        float t1 = m.mData[0] * m.mData[4];
        float t2 = m.mData[0] * m.mData[7];
        float t3 = m.mData[3] * m.mData[1];
        float t4 = m.mData[6] * m.mData[1];
        float t5 = m.mData[3] * m.mData[2];
        float t6 = m.mData[6] * m.mData[2];

        float det = (t1 * m.mData[8] - t2 * m.mData[5] - t3 * m.mData[8] + t4 * m.mData[5] + t5 * m.mData[7] - t6 * m.mData[4]);
        
        if (det == 0.0) return;
        
        float invd = 1.0f/det;
        
        float m0 = (m.mData[4] * m.mData[8] - m.mData[7] * m.mData[5]) * invd;
        float m3 =  -(m.mData[3] * m.mData[8] - m.mData[6] * m.mData[5]) * invd;
        float m6 = (m.mData[3] * m.mData[7] - m.mData[6] * m.mData[4]) * invd;
        float m1 =  -(m.mData[1] * m.mData[8] - m.mData[7] * m.mData[2]) * invd;
        float m4 = (m.mData[0] * m.mData[8] - t6) * invd;
        float m7 =  -(t2 - t4) * invd;
        float m2 = (m.mData[1] * m.mData[5] - m.mData[4] * m.mData[2]) * invd;
        float m5 =  -(m.mData[0] * m.mData[5] - t5) * invd;
        float m8 = (t1 - t3) * invd;
        
        mData[0] = m0;
        mData[3] = m3;
        mData[6] = m6;
        mData[1] = m1;
        mData[4] = m4;
        mData[7] = m7;
        mData[2] = m2;
        mData[5] = m5;
        mData[8] = m8;
    }
    Matrix3 Matrix3::getInverseOfMatrix() const {
        Matrix3 result;
        result.setMatrixAsInverseOfGivenMatrix(*this);
        return result;
    }
    void Matrix3::invertMatrix() {
        setMatrixAsInverseOfGivenMatrix(*this);
    }
    float Matrix3::getMatrixDeterminant() const {
        float t1 = mData[0] * mData[4];
        float t2 = mData[0] * mData[7];
        float t3 = mData[3] * mData[1];
        float t4 = mData[6] * mData[1];
        float t5 = mData[3] * mData[2];
        float t6 = mData[6] * mData[2];
        
        float det = (t1 * mData[8] - t2 * mData[5] - t3 * mData[8] + t4 * mData[5] + t5 * mData[7] - t6 * mData[4]);
        
        return det;
    }
    void Matrix3::setMatrixAsTransposeOfGivenMatrix(const Matrix3& m) {
        mData[0] = m.mData[0];
        mData[3] = m.mData[1];
        mData[6] = m.mData[2];
        mData[1] = m.mData[3];
        mData[4] = m.mData[4];
        mData[7] = m.mData[5];
        mData[2] = m.mData[6];
        mData[5] = m.mData[7];
        mData[8] = m.mData[8];
    }
    Matrix3 Matrix3::getTransposeOfMatrix() const {
        Matrix3 result;
        result.setMatrixAsTransposeOfGivenMatrix(*this);
        return result;
    }
    void Matrix3::invertAndTransposeMatrix() {
        float det = mData[0] * (mData[4] * mData[8] - mData[5] * mData[7]) - mData[3] * (mData[1] * mData[8] - mData[2] * mData[7]) +  mData[6] * (mData[1] * mData[5] - mData[2] * mData[4]);
        
        Matrix3 transpose;
        
        transpose.mData[0] = mData[0];
        transpose.mData[1] = mData[3];
        transpose.mData[2] = mData[6];
        transpose.mData[3] = mData[1];
        transpose.mData[4] = mData[4];
        transpose.mData[5] = mData[7];
        transpose.mData[6] = mData[2];
        transpose.mData[7] = mData[5];
        transpose.mData[8] = mData[8];
        float m11, m12, m13, m21, m22, m23, m31, m32, m33;
        
        m11 =  + (transpose.mData[4] * transpose.mData[8] - transpose.mData[5] * transpose.mData[7])/det;
        m12 =  -(transpose.mData[1] * transpose.mData[8] - transpose.mData[2] * transpose.mData[7])/det;
        m13 =  + (transpose.mData[1] * transpose.mData[5] - transpose.mData[2] * transpose.mData[4])/det;
        
        m21 =  -(transpose.mData[3] * transpose.mData[8] - transpose.mData[5] * transpose.mData[6])/det;
        m22 =  + (transpose.mData[0] * transpose.mData[8] - transpose.mData[2] * transpose.mData[6])/det;
        m23 =  -(transpose.mData[0] * transpose.mData[5] - transpose.mData[2] * transpose.mData[3])/det;
        
        m31 =  + (transpose.mData[3] * transpose.mData[7] - transpose.mData[4] * transpose.mData[6])/det;
        m32 =  -(transpose.mData[0] * transpose.mData[7] - transpose.mData[1] * transpose.mData[6])/det;
        m33 =  + (transpose.mData[0] * transpose.mData[4] - transpose.mData[1] * transpose.mData[3])/det;
        
        Matrix3 presult;
        
        presult.mData[0] = m11;
        presult.mData[1] = m21;
        presult.mData[2] = m31;
        presult.mData[3] = m12;
        presult.mData[4] = m22;
        presult.mData[5] = m32;
        presult.mData[6] = m13;
        presult.mData[7] = m23;
        presult.mData[8] = m33;
        
        mData[0] = presult.mData[0];
        mData[1] = presult.mData[3];
        mData[2] = presult.mData[6];
        mData[3] = presult.mData[1];
        mData[4] = presult.mData[4];
        mData[5] = presult.mData[7];
        mData[6] = presult.mData[2];
        mData[7] = presult.mData[5];
        mData[8] = presult.mData[8];
    }
    

    void Matrix3::turnMatAboutXAxisByAngle(float uNgl) {
        uNgl = DegreesToRad(uNgl);
        
        (*this).setMatrixAsIdentityMatrix();
        
        Matrix3 m(1.0, 0.0, 0.0, 
                0.0, cos(uNgl),  -sin(uNgl), 
                0.0, sin(uNgl), cos(uNgl));
        
        *this = m * (*this);
    }
    void Matrix3::turnMatAboutYAxisByAngle(float uNgl) {
        uNgl = DegreesToRad(uNgl);
        (*this).setMatrixAsIdentityMatrix();
        
        Matrix3 m(cos(uNgl), 0.0, sin(uNgl), 
                0.0, 1.0, 0.0, 
                -sin(uNgl), 0.0, cos(uNgl));
        
        *this = m * (*this);
    }  
    void Matrix3::turnMatAboutZAxisByAngle(float uNgl) {
        uNgl = DegreesToRad(uNgl);
        (*this).setMatrixAsIdentityMatrix();
        
        Matrix3 m(cos(uNgl), -sin(uNgl), 0.0, 
                sin(uNgl), cos(uNgl), 0.0, 
                0.0, 0.0, 1.0);
        
        *this = m * (*this);
    }

    void Matrix3::transformMatAboutXAxisByAngle(float uNgl) {
        uNgl = DegreesToRad(uNgl);
        
        Matrix3 m(1.0, 0.0, 0.0, 
                0.0, cos(uNgl),  -sin(uNgl), 
                0.0, sin(uNgl), cos(uNgl));
        
        *this = m * (*this);
    }
    void Matrix3::transformMatAboutYAxisByAngle(float uNgl) {
        uNgl = DegreesToRad(uNgl);
        
        Matrix3 m(cos(uNgl), 0.0, sin(uNgl), 
                0.0, 1.0, 0.0, 
                -sin(uNgl), 0.0, cos(uNgl));
        
        *this = m * (*this);
    }
    void Matrix3::transformMatAboutZAxisByAngle(float uNgl) {
        uNgl = DegreesToRad(uNgl);
        
        Matrix3 m(cos(uNgl),  -sin(uNgl), 0.0, 
                sin(uNgl), cos(uNgl), 0.0, 
                0.0, 0.0, 1.0);
        
        *this = m * (*this);
    }
    
    void Matrix3::show() {
        std::cout << "[" << mData[0] << ", " << mData[3] << ", " << mData[6] << "," << std::endl;
        std::cout << " " << mData[1] << ", " << mData[4] << ", " << mData[7] << "," << std::endl;
        std::cout << " " << mData[2] << ", " << mData[5] << ", " << mData[8] << "]" << std::endl;
    }
    
}