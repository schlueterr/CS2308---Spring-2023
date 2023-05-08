#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

struct Course{
    string courseName;
    float grades[MAX_STUDENTS];
};

float calculateAverageGrade(Course &course, int size){
    float sum = 0.0;
    for (int i = 0; i < size; i++){
        sum += course.grades[i];
    }
    return sum / size;
}

int findHighestAverageGradeIndex(Course courses[], int numCourses, int numStudents){
    float highestAverage = -1.0;
    int highestAverageIndex = -1;

    for (int i = 0; i < numStudents; i++){
        float totalGrade = 0.0;
        for (int j = 0; j < numCourses; j++){
            totalGrade += courses[j].grades[i];
        }
        float averageGrade = totalGrade / numCourses;
        if (averageGrade > highestAverage){
            highestAverage = averageGrade;
            highestAverageIndex = i;
        }
    }
    return highestAverageIndex;
}

int main(){
    Course courses[] = {
        {"Math", {90, 80, 70, 60, 50}},
        {"English", {80, 70, 60, 50, 40}},
        {"Science", {70, 120, 5000, 40, 30}},
        {"History", {60, 50, 40, 30, 20}},
        {"Geography", {50, 40, 30, 20, 10}}
    };
    int numCourses = sizeof(courses) / sizeof(courses[0]);
    int numStudents = 4;
    float studentAverageGrades[MAX_STUDENTS];

    for (int i = 0; i < numStudents; i++){
        float totalGrade = 0.0;
        for (int j = 0; j < numCourses; j++){
            totalGrade += courses[j].grades[i];
        }
        studentAverageGrades[i] = totalGrade / numCourses;
    }

    int highestAvgIndex = findHighestAverageGradeIndex(courses, numCourses, numStudents);

    cout << "Student/Course with highest average: " << courses[highestAvgIndex].courseName << endl;
}