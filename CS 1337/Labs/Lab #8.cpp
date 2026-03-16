/* This program manages student records using an array of structures. It reads
data from a file, makes sorted copies of the array, displays arrays, allows
the user to list top n students, and searches by netID using both linear and
binary search while reporting number of iterations. */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Structure Definition
struct Student {
    int netID;
    string major;
    double GPA;
};

// Function prototypes
void displayArray(Student arr[], int size, string title);
int linearSearchID(Student arr[], int numElems, int value, int &nIter);
int binarySearchID(Student arr[], int numElems, int value, int &nIter);
void modifiedSortGPA(Student array1[], int size);
void modifiedSortID(Student array2[], int size);
 
int main() {
    const int NUM_ELMTS = 18;

    // Original array of Student structures.
    Student studArray[NUM_ELMTS];
    // Array sorted by GPA.
    Student studArraysortedbyGPA[NUM_ELMTS];
    // Array sorted by netID.
    Student studArraysortedbyID[NUM_ELMTS];

    string fileName;
    ifstream inFile;
    int numRecords = 0;

    // Prompt for file name and open file.
    cout << "Enter file name:";
    cin >> fileName;
    inFile.open(fileName);

    // If file cannot open, print required message and exit.
    if (!inFile) {
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
        return 0;
    }

    // Read records from file into original array.
    while (numRecords < NUM_ELMTS &&
           inFile >> studArray[numRecords].netID
                  >> studArray[numRecords].major
                  >> studArray[numRecords].GPA) {
        numRecords++;
    }
    inFile.close();

    // Copy original array into the two arrays that will be sorted.
    for (int i = 0; i < numRecords; i++) {
        studArraysortedbyGPA[i] = studArray[i];
        studArraysortedbyID[i] = studArray[i];
    }

    // Sort the copied arrays.
    modifiedSortGPA(studArraysortedbyGPA, numRecords);
    modifiedSortID(studArraysortedbyID, numRecords);

    // Display arrays.
    displayArray(studArray, numRecords, "Original array:");
    displayArray(studArraysortedbyGPA, numRecords, "Array sorted by GPA:");
    displayArray(studArraysortedbyID, numRecords, "Array sorted by netID:");

    int choice;

    // Loop menu until user chooses quit.
    do {
        cout << endl;
        cout << "***************" << endl;
        cout << "Menu of choices" << endl;
        cout << "***************" << endl;
        cout << "1 - List top n students" << endl;
        cout << "2 - Search on a netID" << endl;
        cout << "3 - Quit" << endl;
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "Enter n:";
            cin >> n;

            // If n is larger than number of records, only show available records.
            int numToShow = n;
            if (numToShow > numRecords) {
                numToShow = numRecords;
            }

            cout << endl;
            cout << "Top " << numToShow << " students are:" << endl;
            cout << endl;

            // Array is sorted by GPA in ascending order, so print from end to start.
            for (int i = numRecords - 1; i >= numRecords - numToShow; i--) {
                cout << fixed << setprecision(2);
                cout << "netID: " << studArraysortedbyGPA[i].netID
                     << ", major: " << studArraysortedbyGPA[i].major
                     << ", GPA: " << studArraysortedbyGPA[i].GPA << endl;
            }
        }
        else if (choice == 2) {
            int searchID;
            int linearIter;
            int binaryIter;

            cout << "Enter netID:";
            cin >> searchID;
            cout << endl;

            // Run linear search on original array.
            int linearIndex = linearSearchID(studArray, numRecords, searchID,
                                             linearIter);

            // Run binary search on array sorted by netID.
            int binaryIndex = binarySearchID(studArraysortedbyID, numRecords,
                                             searchID, binaryIter);

            cout << "Result of linear search:" << endl;
            cout << "------------------------" << endl;
            if (linearIndex == -1) {
                cout << "Student not found" << endl;
            }
            else {
                cout << fixed << setprecision(2);
                cout << "Student found at index " << linearIndex
                     << ", major is " << studArray[linearIndex].major
                     << ", GPA is " << studArray[linearIndex].GPA << endl;
            }
            cout << "It took " << linearIter << " iterations" << endl;
            cout << endl;

            cout << "Result of binary search:" << endl;
            cout << "------------------------" << endl;
            if (binaryIndex == -1) {
                cout << "Student not found" << endl;
            }
            else {
                cout << fixed << setprecision(2);
                cout << "Student found at index " << binaryIndex
                     << ", major is " << studArraysortedbyID[binaryIndex].major
                     << ", GPA is " << studArraysortedbyID[binaryIndex].GPA
                     << endl;
            }
            cout << "It took " << binaryIter << " iterations" << endl;
        }
    } while (choice != 3);

    cout << "Exiting" << endl;

    return 0;
}

/* This function displays an array of Student structures in two-column format.
Each row prints up to two student records with index, netID, major, and GPA. */
void displayArray(Student arr[], int size, string title) {
    cout << title << endl;

    // Underline length based on title size.
    for (int i = 0; i < title.length(); i++) {
        cout << "-";
    }
    cout << endl;

    cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;

    // Print two records on each line when possible.
    for (int i = 0; i < size; i = i + 2) {
        cout << fixed << setprecision(2);

        cout << setw(5) << i
             << setw(7) << arr[i].netID
             << setw(7) << arr[i].major
             << setw(6) << arr[i].GPA;

        if (i + 1 < size) {
            cout << setw(8) << i + 1
                 << setw(7) << arr[i + 1].netID
                 << setw(7) << arr[i + 1].major
                 << setw(6) << arr[i + 1].GPA;
        }
        cout << endl;
    }
}

/* This function sorts the array of Student structures according to GPA.
It uses selection sort in ascending order of GPA. */
void modifiedSortGPA(Student array1[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (array1[j].GPA < array1[minIndex].GPA) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            Student temp = array1[i];
            array1[i] = array1[minIndex];
            array1[minIndex] = temp;
        }
    }
}

/* This function sorts the array of Student structures according to netID.
It uses selection sort in ascending order of netID. */
void modifiedSortID(Student array2[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (array2[j].netID < array2[minIndex].netID) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            Student temp = array2[i];
            array2[i] = array2[minIndex];
            array2[minIndex] = temp;
        }
    }
}

/* This function implements linear search. It takes the following arguments:
arr: the array of Student structures, numElems: number of elements of array,
value: netID search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index of the structure where the match is found, -1 if
no match is found. */
int linearSearchID(Student arr[], int numElems, int value, int &nIter) {
    nIter = 0;

    for (int i = 0; i < numElems; i++) {
        nIter++;

        if (arr[i].netID == value) {
            return i;
        }
    }

    return -1;
}

/* This function implements binary search. It takes the following arguments:
arr: the array of Student structures, numElems: number of elements of array,
value: netID search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index of the structure where the match is found, -1 if
no match is found. */
int binarySearchID(Student arr[], int numElems, int value, int &nIter) {
    int first = 0;
    int last = numElems - 1;
    nIter = 0;

    while (first <= last) {
        nIter++;

        int middle = (first + last) / 2;

        if (arr[middle].netID == value) {
            return middle;
        }
        else if (arr[middle].netID < value) {
            first = middle + 1;
        }
        else {
            last = middle - 1;
        }
    }

    return -1;
}