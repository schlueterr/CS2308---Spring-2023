#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int roll_num;
    int marks[5];
};

int findHighestAverage(Student students[], int size){
    double highestAverage = -1.0;
    int highestAverageIndex = -1;

    for (int i = 0; i < size; i++){
        int sum = 0;
        for (int j = 0; j < 5; j++){
            sum += students[i].marks[j];
        }
        double average = static_cast<double>(sum) / 5;
        if (average > highestAverage){
            highestAverage = average;
            highestAverageIndex = i;
        }
    }
    return highestAverageIndex;
}

int main(){
    Student students[] = {
        {"John", 1, {90, 80, 70, 60, 50}},
        {"Jane", 2, {80, 70, 60, 50, 40}},
        {"Jack", 3, {70, 120, 5000, 40, 30}},
        {"Jill", 4, {60, 50, 40, 30, 20}},
        {"Joe", 5, {50, 40, 30, 20, 10}}
    };
    int size = sizeof(students) / sizeof(students[0]);
    int highestAverageIndex = findHighestAverage(students, size);
    if (highestAverageIndex != -1){
        cout << "Student with highest average: " << students[highestAverageIndex].name << endl;
    }
    else{
        cout << "No students found" << endl;
    }
    return 0;
}