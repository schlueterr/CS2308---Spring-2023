#include <iomanip>
#include <iostream>

using namespace std;

// Sets the number of monkeys (rows) and days (columns)
const int NUM_MONKEYS = 3; // Rows
const int NUM_DAYS = 5; // Columns


int main(){
    double monkeyFood[NUM_MONKEYS][NUM_DAYS];
    double totalFood = 0;
    cout << fixed << setprecision(2);

    // Get the amount of food eaten by each monkey for each day
    for (int i = 0; i < NUM_MONKEYS; i++){
        for (int j = 0; j < NUM_DAYS; j++){
            cout << "Enter the amount of food consumed by monkey " << (i+1) << " on day " << (j+1) << ": ";
            cin >> monkeyFood[i][j];

            // Input validation (dont accept a negative number)
            while (monkeyFood[i][j] < 0){
                cout << "Please enter a positive number: ";
                cin >> monkeyFood[i][j];
            }
        }
    }

    // Calculate the total amount of food eaten by the whole family of monkeys   
    for (int i = 0; i < NUM_MONKEYS; i++){
        for (int j = 0; j < NUM_DAYS; j++){
            totalFood += monkeyFood[i][j];
        }
    }

    double averageFood = totalFood / (NUM_MONKEYS * NUM_DAYS);
    cout << "The average amount of food eaten per day by the whole family of monkeys is: " << averageFood << endl;

    // Get the least amount of food consumed during the week by any one monkey
    double least = monkeyFood[0][0];
    for (int i = 0; i < NUM_MONKEYS; i++){
        for (int j = 0; j < NUM_DAYS; j++){
            if (monkeyFood[i][j] < least){
                least = monkeyFood[i][j];
            }
        }
    }
    cout << "The least amount of food consumed during the week by any one monkey is: " << least << endl;

    // Get the greatest amount of food eaten during the week by any one monkey
    double greatest = monkeyFood[0][0];
    for (int i = 0; i < NUM_MONKEYS; i++){
        for (int j = 0; j < NUM_DAYS; j++){
            if (monkeyFood[i][j] > greatest){
                greatest = monkeyFood[i][j];
            }
        }
    }
    cout << "The greatest amount of food eaten during the week by any one monkey is: " << greatest << endl;

    return 0;
}