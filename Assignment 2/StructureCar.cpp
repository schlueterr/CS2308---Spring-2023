// File Name: StructureCar.cpp
// 
// Author: Braden Schlueter (plr61)
// Date: 02/05/2023
// Assignment Number: Unit1_Array_Structure Coding Practice
// CS 2308.258 Spring 2023
// 
// A set of functions, structs, and arrays to practice, given the instructions from Unit1_Array_Structure Coding Practice

#include <iostream>

using namespace std;

struct Car{
    string carMake;
    string carModel;
    int yearModel;
    double cost;
};


int main(){
    Car car1 = {"Ford", "Mustang", 1968, 20000};
    Car cars[25];
    Car cars[35] = {{"Ford", "Taurus", 1997, 21000},
                    {"Honda", "Accord", 1992, 11000},
                    {"Lamborghini", "Countach", 1997, 200000}};
    
    for (int i = 0; i < 3; i++){
        cout << "Car " << i + 1 << ": " << endl;
        cout << "  Make: " << cars[i].carMake << endl;
        cout << "  Model: " << cars[i].carModel << endl;
        cout << "  Year Model: " << cars[i].yearModel << endl;
        cout << "  Cost: $" << cars[i].cost << endl;
        cout << endl; 
    }

    return 0;
}