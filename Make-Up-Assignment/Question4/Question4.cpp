#include <iostream>
#include <iomanip>

using namespace std;

bool isSorted(int* arr, int size){
    for (int i = 0; i < size-1; i++){
        if (*(arr + i) > *(arr + i + 1)){
            return false;
        }
    }
    return true;
}

int main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};
    int arr3[] = {12, 17, 22, 27, 32};

    bool arr1Sorted = isSorted(arr1, 5);
    bool arr2Sorted = isSorted(arr2, 5);
    bool arr3Sorted = isSorted(arr3, 5);

    cout << "arr1 is sorted: " << boolalpha << arr1Sorted << endl;
    cout << "arr2 is sorted: " << boolalpha << arr2Sorted << endl;
    cout << "arr3 is sorted: " << boolalpha << arr3Sorted << endl;

    return 0;
}