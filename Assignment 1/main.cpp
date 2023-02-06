// File Name: main.cpp
// 
// Author: Braden Schlueter (plr61)
// Date: 01/30/2023
// Assignment Number: Coding Practice Unit_1
// CS 2308.258 Spring 2023
// 
// A set of functions and prototypes that was given to write from the canvas assignment "Unit_1 Functions Coding Practice"

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototype for a function called compute
// I had to comment this out to get the program to compile

// double compute(int = 5, long = 65536, double &);


void question1(){
    cout << "Question 1: Indicate which of the following is the function prototype, the function header, and the function call: \n";
    cout <<  "a = The function header\n"; 
    cout <<  "b = The function prototype\n";
    cout <<  "c = The function call\n";
}

void getNumber(int &number){
    cout << "Input a number (1-100): ";
    cin >> number;
    if (number < 1 || number > 100) {
        cout << "Invalid input. Please enter a number between 1 and 100." << endl;
        getNumber(number);
    }
}

void timesTen(int number){
    int result =  number * 10;
    cout << "The product of " << number << " times 10 is " << result << endl;
}

double Celsius(double fahrenheit){
    return (5.0/9.0) * (fahrenheit - 32);
}

int main(){
    question1();
    cout << endl;

    // Test cases for the timesTen function
    timesTen(5);
    timesTen(10);
    timesTen(15);

    cout << endl;

    // Test cases for the question4 function
    int number;
    getNumber(number);
    cout << "\nTest Case: You picked number " << number << endl;
    cout << endl;

    // Test cases for the Celsius function
    for (int i = 0; i <= 20; i++){
        cout << "Fahrenheit: " << i << " Celsius: " << Celsius(i) << endl;
    }


    return 0;
}