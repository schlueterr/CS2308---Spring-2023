// File Name: card.cpp
// 
// Author: Braden Schlueter plr61@txstate.edu
// Date: 03/01/2023
// Assignment Number: 1
// CS 2308.258 Spring 2023
// 
// This program imitates a simple database containing a bicycle race. It reads input from dataset.txt and displays the results in a table. 
// The user can then choose to sort the results by bib number, distance, or time. The user can also search for a racer by name or bib number.

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


//***********************************************************
// readDataset: reads data from dataset.txt and stores it in an array of structs
//
// in: input file stream
// results[]: array of structs
// size: size of array
// returns: size of array
//***********************************************************
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

//***********************************************************
// displayMenu: displays the menu for the user to choose from
//
// returns: void
//***********************************************************
void displayMenu(){
    cout << "\nMenu\n\n";
    cout << "1. Display results sorted by bib number\n";
    cout << "2. Display results sorted by distance, then time\n";
    cout << "3. Lookup a bib number given a name\n";
    cout << "4. Lookup a result by bib number \n";
    cout << "5. Quit the Program\n\n";
    cout << "Enter your choice: ";
}

//***********************************************************
// displayHeader: displays the header for the results table
//
// returns: void
//***********************************************************
void displayHeader(){
    cout << left 
         << setw(7) << "BibNum"
         << setw(18) << "Name"
         << right
         << setw(8) << "Distance"
         << setw(10) << "Time"
         << endl;
}

//***********************************************************
// displayDataset: displays the results table
//
// results[]: array of structs
// size: size of array
// returns: void
//***********************************************************
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

//***********************************************************
// function name: short description of what the function does.
//
// results[]: array of structs
// size: size of array
// returns: void
//***********************************************************
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

//***********************************************************
// linearSearchByName: searches for a racer's bibNumber by name using linear search
//
// results[]: array of structs
// size: size of array
// racerName: name of racer to search for
// returns: The racer's bibNumber if found, -1 if not found
//***********************************************************
int linearSearchByName(Result results[], int size, string racerName){
    for (int i = 0; i < size; i++){
        if (results[i].name == racerName){
            return results[i].bibNumber;
        }
    }
    return -1; // not found
}

//***********************************************************
// binarySearchByNumber: searches for a racer's name by bibNumber using binary search
//
// results[]: array of structs
// size: size of array
// targetNumber: bibNumber of racer to search for
// returns: the racers bibNumber index if found, -1 if not found
//***********************************************************
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

//***********************************************************
// bubbleSortByNumber: sorts the results array by bibNumber using bubble sort
//
// results[]: array of structs
// size: size of array
// returns: void
//***********************************************************
void bubbleSortByNumber(Result results[], int size){
    bool swap;
    Result temp;
    do{
        swap = false;
        for (int i = 0; i < (size-1); i++){
            if (results[i].bibNumber > results[i+1].bibNumber){
                temp = results[i];
                results[i] = results[i+1];
                results[i+1] = temp;
                swap = true;
            }
        }
    }
    while (swap);
}

//***********************************************************
// sortByDistanceTime: sorts the results array by distance, then time using bubble sort
//
// results[]: array of structs
// size: size of array
// returns: void
//***********************************************************
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


int main(){
    int choice, userBibNumber, count;
    string racerName;
    ifstream fin;
    Result info[30];
    cout << fixed << setprecision(1);

    fin.open("dataset.txt");
    readDataset(fin, info, count);
    fin.close();
    Result results[count];
    for (int i = 0; i < count; i++){
        results[i] = info[i];
    }

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
            bubbleSortByNumber(results, count);
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