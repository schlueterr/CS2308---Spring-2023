// This program uses the bubble sort algorithm to sort an
// array in ascending order.
#include <iostream>
using namespace std;


void showArray(const int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
}

void bubbleSort(int array[], int size)
{
   bool swap;
   int temp;

   do {
      swap = false;
      for (int count = 0; count < (size - 1); count++)
      {
         if (array[count] > array[count + 1])
         {
            temp = array[count];
            array[count] = array[count + 1];
            array[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}

int main()
{
   // Array of unsorted values
   int values[6] = {7, 2, 3, 8, 9, 1};

   // Display the values.
   cout << "The unsorted values are:\n";
   showArray(values, 6);

   // Sort the values.
   bubbleSort(values, 6);

   // Display them again.
   cout << "The sorted values are:\n";
   showArray(values, 6);
   return 0;
}




