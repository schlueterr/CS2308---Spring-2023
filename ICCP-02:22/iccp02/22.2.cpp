#include <iostream>

using namespace std;


void SelectionSortDescendTrace( int arr[], int size){
    int largestIndex = 0;
    for(int i = 0; i < size-1; i++){
        largestIndex = i;
        for (int j = i+1; j < size; j++){
            if (arr[j] > arr[largestIndex]){
                largestIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[largestIndex];
        arr[largestIndex] = temp;

        for(int k = 0; k < size; k++){
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[10];
    int inputNum = 0;
    int arrSize = 0;
    cout << "Enter no more than 10 positive numbers. Enter -1 to stop." << endl;
    while(arrSize < 10){
        cin >> inputNum;
        if(inputNum == -1){
            break;
        }
        if(inputNum < 0){
            cout << "Please enter a positive number" << endl;
            continue;
        }
        arr[arrSize] = inputNum;
        arrSize++;
    }

    cout << "The numbers currently in the array are: " << endl;
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }

    SelectionSortDescendTrace(arr, arrSize);
}