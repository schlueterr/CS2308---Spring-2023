// This is the main file for assignment 1 (project 1).
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// Include struct definitions
struct Result{
    int bibNumber;
    string name;
    double distance;
    string time;
};

// Create the display menu
void displayMenu(){
    cout << "\nMenu\n\n";
    cout << "1. Display results sorted by bib number\n";
    cout << "2. Display results sorted by distance, then time\n";
    cout << "3. Lookup a bib number given a name\n";
    cout << "4. Lookup a result by bib number \n";
    cout << "5. Quit the Program\n\n";
    cout << "Enter your choice: ";
}

// Functions needed per the assignment instructions
void readDataset(ifstream& in, Result results[], int &size); 
void displayDataset(Result results[], int size); 
int linearSearchByName(Result results[], int size, string targetName); 
int binarySearchByNumber(Result results[], int size, int targetNumber); 
void sortByNumber(Result results[], int size); 
void sortByDistanceTime(Result results[], int size); 



int main(){
    int choice;
    
    displayMenu();
    cin >> choice;
    cout << choice << endl;
}