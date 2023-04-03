#include <iostream>
#include <string>

#include "Drink.h"
using namespace std;

int main(){
    Drink Coke("Coke");
    Drink Beer("Beer");

    Coke.setPrice(2.50);
    Coke.setQuantity(10);

    Beer.setPrice(3.50);
    Beer.setQuantity(5);


    cout << "The total cost of Coke: " << Coke.totalCost() << endl;
    cout << "The total cost of Beer: " << Beer.totalCost() << endl;
    cout << "The total cost of these two drinks are: "
         << Coke.totalCost() + Beer.totalCost() << endl;
}