#include <string>
#include <iostream>
using namespace std;

struct Student {
    string name;
    int roll_no;
    int *marks;
};

// takes an array of student structures and its size as input and returns the index of the student with the highest average mark
int arrayAverage(Student student[], int size){
    int maxIndex = 0;
    double maxAverage = 0;
    for (int i = 0; i < size; i++){
        double sum = 0;
        for(int i = 0; i < 5; i++){
            sum += student[i].marks[i];
        }
        double average = sum / 5;
        if (average > maxAverage){
            maxAverage = average;
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main(){
    int marksS1[5] = {12, 17, 20, 25, 30};
    
}