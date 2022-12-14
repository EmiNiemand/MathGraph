//
// Created by szymo on 08/10/2022.
//

#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H

#include <iostream>
#include <math.h>

class Vector {
private:
    float x, y, z;
public:
    Vector();
    Vector(float x, float y, float z);
    Vector(Vector p1, Vector p2);
    Vector(const Vector &v);
    ~Vector();

    void operator+=(const Vector& v);
    void operator-=(const Vector& v);
    void operator*=(const float& s);
    void operator/=(const float& s);

    Vector operator+(const Vector& v);
    Vector operator-(const Vector& v);
    Vector operator*(const float& s);
    Vector operator/(const float& s);

    void add(Vector v);
    void sub(Vector v);
    void mul(float s);
    void div(float s);

    float length();
    void normalize();
    static Vector dot(Vector& v1, Vector& v2);
    static float dotProduct(Vector& v1, Vector& v2);
    static Vector cross(Vector& v1, Vector& v2);

    static float calcAngle(Vector& v1, Vector& v2);

    std::string toString();
};


#endif //VECTORS_VECTOR_H
