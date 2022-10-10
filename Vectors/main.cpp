#include <iostream>
#include <sstream>
#include <vector>
#include "Vector.h"

#pragma region Predirectives
Vector vectorFromInput(Vector defaultVector);
void testAddition();
void testAngle();
void testPerpendicular();
void testNormalize();
#pragma endregion

int main() {
    bool quit = false;
    std::string userChoice = "";
    while(!quit) {
        printf("=== VECTOR OPERATIONS MENU ===\n");
        printf("\t1. Check commutativity of addition (if A+B==B+A)\n");
        printf("\t2. Check angle between vectors\n");
        printf("\t3. Calculate perpendicular vector\n");
        printf("\t4. Normalize vector\n");
        printf("\t[q - quit]\n");
        printf("Choose option: ");
        std::getline(std::cin, userChoice);
        printf("\n");

        if(userChoice == "q") {
            quit = true;
            continue;
        }

        if(userChoice.length() != 1 || userChoice == "") {
            system("cls");
            continue;
        }

        switch(std::stoi(userChoice)) {
            case 1: testAddition(); break;
            case 2: testAngle(); break;
            case 3: testPerpendicular(); break;
            case 4: testNormalize(); break;
        }

        system("pause");
        system("cls");
    }
    return 0;
}

Vector vectorFromInput(Vector defaultVector) {
    printf("Input x, y z values separated by space (e.g. 1 2 3)\n");
    printf("(%s): ", defaultVector.toString().c_str());
    std::string vectorInString;
    std::getline(std::cin, vectorInString);
    printf("\n");

    if(vectorInString == "") return defaultVector;

    float coordinate;
    std::vector<float> coordinates;
    std::stringstream ss(vectorInString);
    while(ss >> coordinate) {
        coordinates.push_back(coordinate);
    }
    return Vector(coordinates.at(0), coordinates.at(1), coordinates.at(2));
}

void testAddition() {
    Vector v1 = vectorFromInput(Vector(0, 3, 0));
    Vector v2 = vectorFromInput(Vector(5, 5, 0));

    Vector temp = v1 + v2;
    printf("%s + %s = %s\n", v1.toString().c_str(), v2.toString().c_str(), temp.toString().c_str());
    temp = v2 + v1;
    printf("%s + %s = %s\n\n", v2.toString().c_str(), v1.toString().c_str(), temp.toString().c_str());
}

void testAngle() {
    Vector v1 = vectorFromInput(Vector(0, 3, 0));
    Vector v2 = vectorFromInput(Vector(5, 5, 0));

    float angle = Vector::calcAngle(v1, v2);
    printf("%f rad\n", angle);
    printf("%f degrees\n", angle * 180 / M_PI);
}

void testPerpendicular() {
    Vector v1 = vectorFromInput(Vector(4, 5, 1));
    Vector v2 = vectorFromInput(Vector(4, 1, 3));

    printf("%s perpendicular vector\n", Vector::cross(v1, v2).toString().c_str());
}

void testNormalize() {
    Vector v1 = vectorFromInput(Vector(4, 5, 1));

    printf("before normalizing: %s, size: %f\n", v1.toString().c_str(), v1.length());
    v1.normalize();
    printf("after normalizing: %s, size: %f\n", v1.toString().c_str(), v1.length());
}