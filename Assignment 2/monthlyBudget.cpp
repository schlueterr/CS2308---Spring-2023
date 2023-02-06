// File Name: monthlyBudget.cpp
// 
// Author: Braden Schlueter (plr61)
// Date: 02/05/2023
// Assignment Number: Unit1_Array_Structure Coding Practice
// CS 2308.258 Spring 2023
// 
// A set of functions, structs, and arrays to practice, given the instructions from Unit1_Array_Structure Coding Practice

#include <iostream>
#include <string>

using namespace std;

struct MonthlyBudget 
{ 
    double housing; 
    double utilities; 
    double householdExpenses; 
    double transportation; 
    double food; 
    double medical; 
    double insurance; 
    double entertainment; 
    double clothing; 
    double miscellaneous; 
};

void enterBudget(MonthlyBudget &budget) 
{
    cout << "Enter Housing expense: $";
        cin >> budget.housing;
    cout << "Enter Utilities expense: $";
        cin >> budget.utilities;
    cout << "Enter Household Expenses expense: $";
        cin >> budget.householdExpenses;
    cout << "Enter Transportation expense: $";
        cin >> budget.transportation;
    cout << "Enter Food expense: $";
        cin >> budget.food;
    cout << "Enter Medical expense: $";
        cin >> budget.medical;
    cout << "Enter Insurance expense: $";
        cin >> budget.insurance;
    cout << "Enter Entertainment expense: $";
        cin >> budget.entertainment;
    cout << "Enter Clothing expense: $";
        cin >> budget.clothing;
    cout << "Enter Miscellaneous expense: $";
        cin >> budget.miscellaneous;
}

void displayReport(MonthlyBudget budget) 
{
    const double budgetHousing = 500;
    const double budgetUtilities = 150;
    const double budgetHouseholdExpenses = 65;
    const double budgetTransportation = 50;
    const double budgetFood = 250;
    const double budgetMedical = 30;
    const double budgetInsurance = 100;
    const double budgetEntertainment = 150;
    const double budgetClothing = 75;
    const double budgetMiscellaneous = 50;

    cout << "\nExpense Report:\n" << endl;
    cout << "Housing: $" << budget.housing - budgetHousing << (budget.housing - budgetHousing >= 0 ? " over" : " under") << endl;
    cout << "Utilities: $" << budget.utilities - budgetUtilities << (budget.utilities - budgetUtilities >= 0 ? " over" : " under") << endl;
    cout << "Household Expenses: $" << budget.householdExpenses - budgetHouseholdExpenses << (budget.householdExpenses - budgetHouseholdExpenses >= 0 ? " over" : " under") << endl;
    cout << "Transportation: $" << budget.transportation - budgetTransportation << (budget.transportation - budgetTransportation >= 0 ? " over" : " under") << endl;
    cout << "Food: $" << budget.food - budgetFood << (budget.food - budgetFood >= 0 ? " over" : " under") << endl;
    cout << "Medical: $" << budget.medical - budgetMedical << (budget.medical - budgetMedical >= 0 ? " over" : " under") << endl;
    cout << "Insurance: $" << budget.insurance - budgetInsurance << (budget.insurance - budgetInsurance >= 0 ? " over" : " under") << endl;
    cout << "Entertainment: $" << budget.entertainment - budgetEntertainment << (budget.entertainment - budgetEntertainment >= 0 ? " over" : " under") << endl;
    cout << "Clothing: $" << budget.clothing - budgetClothing << (budget.clothing - budgetClothing >= 0 ? " over" : " under") << endl;
    cout << "Miscellaneous: $" << budget.miscellaneous - budgetMiscellaneous << (budget.miscellaneous - budgetMiscellaneous >= 0 ? " over" : " under") << endl;

    double totalSpent = budget.housing + budget.utilities + budget.householdExpenses + budget.transportation + budget.food + budget.medical + budget.insurance + budget.entertainment + budget.clothing + budget.miscellaneous;
    double totalBudget = budgetHousing + budgetUtilities + budgetHouseholdExpenses + budgetTransportation + budgetFood + budgetMedical + budgetInsurance + budgetEntertainment + budgetClothing + budgetMiscellaneous;
    cout << "\nTotal spent: $" << totalSpent << endl;
    cout << "Total budget: $" << totalBudget << endl;
    cout << "Amount spent: $" << totalSpent - totalBudget << (totalSpent - totalBudget >= 0 ? " over" : " under") << endl;

}

int main(){
    MonthlyBudget budget;
    enterBudget(budget);
    displayReport(budget);
    return 0;
}