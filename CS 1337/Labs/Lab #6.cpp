/* This program reads an array of integers from the user and creates a new 
array that is one element larger. The new array has a 0 in the first position 
and all original elements are shifted one position to the right. */
#include <iostream>
using namespace std;

// Function Prototypes
int* shiftArray(int arr[], int size);
void displayArray(int arr[], int size);

int main() {
    // Define variables
    int size;
    int oldArray[size];

    // Get the size of the array from the user
    cin >> size;

    // Input all of the user values into the array
    for (int i = 0; i < size; i++) {
        cin >> oldArray[i];
    }

    // Use the function shiftArray() to create a new array with a leading zero.
    int* newArray = shiftArray(oldArray, size);
    // Use the function displayArray() to display the shifted array.
    displayArray(newArray, size + 1);

    return 0;
}

/* shiftArray creates a new dynamically allocated array that is one element 
larger than the original array. It places 0 in the first position and copies 
all elements from the original array shifted one position to the right. */
int* shiftArray(int arr[], int size) {
    // Allocate new array one element larger.
    int* biggerArray = new int[size + 1];

    // Set the first element to 0.
    biggerArray[0] = 0;

    // Copy and shift each original element one index to the right.
    for (int i = 0; i < size; i++) {
        biggerArray[i + 1] = arr[i];
    }

    return biggerArray;
}

/* displayArray prints all elements of an array to the console, separated by 
spaces, followed by a newline. */
void displayArray(int arr[], int size) {
    // Loop through each element in the array and output the array with a space
    // between each array index
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}