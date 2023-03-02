// This is the main file for assignment 1 (project 1).
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int count = 10;

// Include struct definitions
struct Result{
    int bibNumber;
    string name;
    double distance;
    string time;
};

int readDataset(ifstream& in, Result results[], int &size){
    // fin.open("dataset.txt");
    int count = 0;
    while(in){
        in >> results[count].bibNumber;

        in >> ws;
        getline(in, results[count].name);

        in >> results[count].distance;

        in >> results[count].time;

        count++;
    }
    return size = count - 1;
}

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
    return -1; // not found
}

int binarySearchByNumber(Result results[], int size, int targetNumber){
    int mid;
    int low = 0;
    int high = size - 1;

    while (high >= low) {
        mid = (high + low) / 2;
        if (results[mid].bibNumber < targetNumber) {
            low = mid + 1;
        }
        else if (results[mid].bibNumber > targetNumber) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1; // not found
}

void sortByDistanceTime(Result results[], int size){
    bool swap;
    int temp;
    do{
        swap = false;
        for (int i = 0; i < (size-1); i++){
            if (results[i].distance < results[i+1].distance){
                temp = results[i].distance;
                results[i].distance = results[i+1].distance;
                results[i+1].distance = temp;
                swap = true;
            }
        }
    }
    while (swap);
    displayDataset(results, size);
}


// Functions needed per the assignment instructions
// void readDataset(ifstream& in, Result results[], int &size); 
// void displayDataset(Result results[], int size); 
// int linearSearchByName(Result results[], int size, string targetName); 
// int binarySearchByNumber(Result results[], int size, int targetNumber); 
// void sortByNumber(Result results[], int size); 
// void sortByDistanceTime(Result results[], int size); 



int main(){
    int choice, userBibNumber, count;
    string racerName;
    ifstream fin;
    Result info[10];
    cout << fixed << setprecision(1);

    fin.open("dataset.txt");
    readDataset(fin, info, count);
    fin.close();
    Result results[count];
    for (int i = 0; i < count; i++){
        results[i] = info[i];
    }


   /* Result results[] = {  // This is testing data DELETE LATER
                       {30, "John Smith", 122.0, "05:40:52"},
                       {20, "Gary Benson", 115.9, "05:50:40"},
                       {25, "David Myers", 103.7, "05:53:16"}
    };
    int count = 3;
   */

    displayMenu();
        cin >> choice;
    while (choice < 1 || choice > 5){ // Validate the user's choice
        cout << "Invalid choice. Please enter a number between 1 and 5: ";
            cin >> choice;
            continue;
    }
    switch (choice){
        case 1:
            // display results sorted by bib number
            sortByNumber(results, count);
            break;
        case 2:
            // display results sorted by distance, then time
            sortByDistanceTime(results, count);
            break;
        case 3:
            // lookup a bib number given a name
            // Need to add input for targetName, and use cin to get the 
            cout << "Enter a name of the racer to look for: ";
                cin >> ws;
                getline(cin, racerName);
            if (linearSearchByName(results, count, racerName) == -1){
                cout << "\nNo racer found with name: " << racerName << endl;
                break;
            }
            cout << "\nThe number of the racer with name " << racerName << " is: " << linearSearchByName(results, count, racerName) << endl;
            break;
        case 4:
            // lookup a result by bib number
            cout << "Enter number of a racer to look for: ";
                cin >> userBibNumber;
            if (binarySearchByNumber(results, count, userBibNumber) == -1){
                cout << "\nNo racer found with number: " << userBibNumber << endl;
                break;
            }
            cout << "\n"
                 << left
                 << setw(5) << results[binarySearchByNumber(results, count, userBibNumber)].bibNumber
                 << setw(18) << results[binarySearchByNumber(results, count, userBibNumber)].name
                 << right
                 << setw(8) << results[binarySearchByNumber(results, count, userBibNumber)].distance
                 << setw(10) << results[binarySearchByNumber(results, count, userBibNumber)].time
                 << endl;
            break;
        case 5:
            // quit the program
            cout << "Exiting the program...";
            return 0;
            break;

    }
    

}