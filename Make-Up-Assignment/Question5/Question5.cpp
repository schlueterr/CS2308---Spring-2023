#include <iostream>
using namespace std;

int *grow(int *arr, int size){
    int newSize = size * 2;
    int *newArr = new int[newSize];

    for (int i = 0; i < size; i++){
        newArr[i * 2] = arr[i];
        newArr[i * 2 + 1] = arr[i];
    }
    return newArr;
}

int main(){
    int x[] = {4, 5, 6};
    int size = sizeof(x) / sizeof(x[0]);

    int *newArr = grow(x, size);

    for (int i = 0; i < size * 2; i++){
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete[] newArr;

    return 0;
}