#include <iostream>

using namespace std;

// Question 1
void smallest_Array_Value(){
    const int SIZE = 10;
    int array[SIZE];
    int largest = -99999;
    int smallest = 99999;

    for (int i = 0; i < SIZE; i++){
        cout << "Enter value " << (i+1) << ": ";
        cin >> array[i];

        if (array[i] > largest){
            largest = array[i];
        }

        if (array[i] < smallest){
            smallest = array[i];
        }
    }
    
    cout << "The largest value is: " << largest << endl;
    cout << "The smallest value is: " << smallest << endl;
}

void display_Array(int arr[], int size, int n){
    cout << "The numbers greater than " << n << ": ";
    for (int i = 0; i < size; i++){
        if (arr[i] > n){
            cout << arr[i] << " ";
        }
    }
}

int main(){
    // Display Quesiton 1
    smallest_Array_Value();
    cout << endl;

    // Display Question 2
    int arr[] = {2, 5, 8, 12, 18, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 9;
    
    display_Array(arr, size, n);
    cout << endl;


    
    return 0;
}