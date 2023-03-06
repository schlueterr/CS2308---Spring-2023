#include <iostream> 

using namespace std;

int *inputArray(int n){
    int *arr = new int[n];

    cout << "Enter " << n << " integers: " << endl;

    for (int i = 0; i < n; i++){
        cin >> *(arr + i); // or arr[i]
    }

    return arr;
}

void swap1(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int size;
    
    cout << "Enter the size of the array: " << endl;
        cin >> size;
   
    int *arr = inputArray(size);

    cout << "Display the array: " << endl;
    for (int i = 0; i < size; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete [] arr;

    int x = 5, y = 10;
    cout << "Before swap: x = " << x << " y = " << y << endl;
    swap1(&x, &y);
    cout << "After swap: x = " << x << " y = " << y << endl;

    return 0;
}