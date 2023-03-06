#include <iostream> 

using namespace std;

void leftCircularShift(int *arr, int size){
    int first = *(arr);


    for(int i = 0; i < size - 1; i++){
       *(arr + i) = *(arr + i + 1);
    }

    *(arr + size - 1) = first;
}

int* reverse(int *arr, int size){
    int *newArray = new int[size];

    
    for (int i = 0; i <size; i++){
        *(newArray + i) = *(arr + size - 1 - i);
    }
    
    
    return newArray;
} 


int main(){
    int arr[5] = {1, 7, 9, 12, 24 };
    int size = 5;

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl; 

    leftCircularShift(arr, size);

    for(int i=0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Reverse the array: " << endl;
    int *newArray2 = reverse(arr, size);
    for(int i = 0; i < size; i++){
        cout << *(newArray2 + i) << " ";
    }

    delete [] newArray2;

    return 0;
}



