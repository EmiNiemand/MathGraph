#include <iostream>
#include "Vector.h"

int main() {
    Vector v1 = Vector(0, 3, 0);
    Vector v2 = Vector(5, 5, 0);
    Vector v3 = Vector(4, 5, 1);
    Vector v4 = Vector(4, 1, 3);

    Vector temp = v1 + v2;
    printf("[0, 3, 0] + [5, 5, 0] = %s\n", temp.toString().c_str());
    temp = v2 + v1;
    printf("[5, 5, 0] + [0, 3, 0] = %s\n", temp.toString().c_str());

    float angle = Vector::calcAngle(v1, v2);
    printf("%f rad\n", angle);
    angle = Vector::calcAngle(v1, v2);
    printf("%f degrees\n", angle * 180 / M_PI);

    temp = Vector::cross(v3, v4);
    printf("%s perpendicular vector\n", temp.toString().c_str());

    printf("before normalizing: %s, size: %f\n", v3.toString().c_str(), v3.length());
    v3.normalize();
    printf("after normalizing: %s, size: %f\n", v3.toString().c_str(), v3.length());
}
