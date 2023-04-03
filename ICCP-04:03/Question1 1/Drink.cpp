#include "Drink.h"
#include <string>
using namespace std;

Drink::Drink(string n){
    name = n;
    price = 0.0;
    quantity = 0;
}

void Drink::setPrice(double p){
    price = p;
}

void Drink::setQuantity(int q){
    quantity = q;
}

double Drink::getPrice(){
    return price;
}

int Drink::getQuantity(){
    return quantity;
}

double Drink::totalCost(){
    return price * quantity;
}
        