/* This program sorts a list of numbers without modifying the original array. 
It uses a second array of pointers to sort the values without changing the 
original data. */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime> // contains prototype for function time
using namespace std;

#define SIZE 40

// Function prototypes
void printArray(int randArray[]);       
void bubbleSort(int* list[]);           
void printPointerArray(int* ptrArray[]);
void swapIntPtr(int** xptr, int** yptr);

int main() {
    // Define variables
    int dataArray[SIZE] = {0};
    int *pointerArray[SIZE];
    int seed;

    // Seed the random number generator
    cout << "Enter seed: ";
    cin >> seed;
    srand(seed);

    // Initializing values in Data Array
    for (int index = 0; index < SIZE; index++) {
        // Keep values between 0 to 2999
        dataArray[index] = rand() % 3000;
        // Stores the address of each element
        pointerArray[index] = &dataArray[index];
    }

    // Printing four different data sets 
    printf("Before Sorting, values in Data Array: \n");
    printArray(dataArray);
    printf("\n");

    // Print the Pointer array before sorting
    printf("Before Sorting, values in Pointer Array and the value it is pointing at: \n");
    printPointerArray(pointerArray);
    printf("\n");

    // Calling function Bubble SOrt
    bubbleSort(pointerArray);

    // Print the Pointer array after sorting
    printf("\n");
    printf("After Sorting, values in Pointer Array and the value it is pointing at:  \n");
    printPointerArray(pointerArray);
    printf("\n");

    // Print the Data array again after sorting to show that the values in the
    // data array are not changed, only the pointers are sorted
    printf("\n");
    printf("After Sorting, values in Data Array: \n");
    printArray(dataArray);
    printf("\n");

    return 0;
}

// This function swaps the addresses stored in two integer pointers using a 
// temporary pointer
void swapIntPtr(int** xptr, int** yptr) {
    int* temp = *xptr;
    *xptr = *yptr;
    *yptr = temp;
}

// This function implements the bubble sort algorithm to sort an array of 
// integer pointers based on the values they point to
void bubbleSort(int* list[]) {
    // Outer loop for number of passes
    for (int i = 0; i < SIZE - 1; i++) {
        // Inner loop for comparing adjacent elements 
        for (int j = 0; j < SIZE - i - 1; j++) {
            // Compare the values pointed to by the current and next pointers, 
            // and swap if they are in the wrong order
            if (*list[j] > *list[j + 1]) {
                swapIntPtr(&list[j], &list[j + 1]);
            }
        }
    }
}

// This function prints the values in the data array
void printArray(int randArray[]) {
    for (int index = 0; index < SIZE; index++) {
        cout << setw(6) << randArray[index] << " ";

        // Print 10 values per line
        if ((index + 1) % 10 == 0) {
            cout << endl;
        }
    }
}

// This function prints the values in the pointer array and the values they 
// point to
void printPointerArray(int* ptrArray[]) {
    for (int index = 0; index < SIZE; index++) {
        // Print the pointer address and the value it is pointing to
        cout << ptrArray[index] << "  " << setw(6) << left << *ptrArray[index];
        
        // Print 4 address/values per line
        if ((index + 1) % 4 == 0) {
            cout << endl;
        }
    }
}