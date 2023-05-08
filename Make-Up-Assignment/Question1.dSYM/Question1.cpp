#include <iostream>
using namespace std;

double calculateAverage(int arr[], int size){
    if (size == 0){
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    double average = static_cast<double>(sum) / size;
    return average;
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    cout << calculateAverage(arr, 5) << endl;
    return 0;
}