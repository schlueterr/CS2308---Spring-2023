#ifndef DRINK_H
#define DRINK_H
#include <string>
using namespace std; 

class Drink{
    private: 
        string name;
        double price;
        int quantity;

    public:
        Drink(string n);
        void setPrice(double p);
        void setQuantity(int q);
        double getPrice();
        string getQuantity();
        double totalCost();
}

#endif