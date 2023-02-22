#include <iostream>
#include <string>


using namespace std;

struct Book { 
 string title; 
 int year; 
}; 

// And the following bubble sort code from class: 
void bubbleSort (Book list [], int size) { 
    bool swapped = false;
    int count = 0;
    do { 
        swapped = false;
        for (int i = 0; i < size-1; i++) { 
            if (list[i].year < list[i+1].year) { 
                //swap 
                Book temp = list[i]; 
                list[i] = list[i+1]; 
                list[i+1] = temp; 
                swapped = true; 
            } 
            count++;
        } 
 } while (swapped == true); 
    cout << "Number of comparisons: " << count << endl;

} 

int main(){
    Book arr[5] = {"Title 1", 2000};

    bubbleSort(arr, 5);
}