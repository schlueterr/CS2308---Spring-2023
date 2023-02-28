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

// Displays a header for the results table
void displayHeader(){
    cout << left 
         << setw(7) << "BibNum"
         << setw(18) << "Name"
         << right
         << setw(8) << "Distance"
         << setw(10) << "Time"
         << endl;
}

void displayDataset(Result results[], int size){
    displayHeader();
    for (int i = 0; i < size; i++){
        cout << left
             << setw(7) << results[i].bibNumber
             << setw(18) << results[i].name
             << right
             << setw(8) << results[i].distance
             << setw(10) << results[i].time
             << endl;
    }
}

void sortByNumber(Result results[], int size){
    bool swap;
    Result temp;
    do {
        swap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (results[count].bibNumber > results[count + 1].bibNumber)
            {
                temp = results[count];
                results[count] = results[count + 1];
                results[count + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
    displayDataset(results, size);
}

int linearSearchByName(Result results[], int size, string racerName){
    for (int i = 0; i < size; i++){
        if (results[i].name == racerName){
            return results[i].bibNumber;
        }
    }
    return -1;
}

// Functions needed per the assignment instructions
void readDataset(ifstream& in, Result results[], int &size); 
// void displayDataset(Result results[], int size); 
// int linearSearchByName(Result results[], int size, string targetName); 
int binarySearchByNumber(Result results[], int size, int targetNumber); 
// void sortByNumber(Result results[], int size); 
void sortByDistanceTime(Result results[], int size); 



int main(){
    int choice;
    string racerName;

    Result results[] = {  // This is testing data DELETE LATER
                       {10, "John Smith", 122.0, "05:40:52"},
                       {20, "Gary Benson", 115.9, "05:50:40"},
                       {25, "David Myers", 103.7, "05:53:16"}
    };
    int count = 3;
    
    displayMenu();
        cin >> choice;
    while (choice < 1 || choice > 5){ // Validate the user's choice
        cout << "Invalid choice. Please enter a number between 1 and 5: ";
            cin >> choice;
    }
    switch (choice){
        case 1:
            // display results sorted by bib number
            sortByNumber(results, count);
            break;
        case 2:
            // display results sorted by distance, then time
            displayDataset(results, count);
            break;
        case 3:
            // lookup a bib number given a name
            // Need to add input for targetName, and use cin to get the 
            cout << "Enter a name of the racer: ";
                cin >> ws;
                getline(cin, racerName);
            cout << "The bib number for " << racerName << " is " << linearSearchByName(results, count, racerName) << "." << endl;
            break;
        case 4:
            // lookup a result by bib number
            break;
        case 5:
            // quit the program
            cout << "Exiting program...";
            return 0;
            break;

    }
    

}