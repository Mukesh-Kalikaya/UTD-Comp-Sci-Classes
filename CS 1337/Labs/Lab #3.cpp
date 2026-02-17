/* This program asks the user for a list of 10 numbers and then uses Selection 
Sort method to sort the numbers from smallest to largest. It then prints the 
sorted array to the user.*/
#include <iostream>
using namespace std;
#define SIZE 10

// Function Prototype
void SelectionSort(int [], int size );

int main() {
    // Declare all the variables and arrays
    int numberList[SIZE];
    int numberRec;
   
    // input validation
    do {
        cout << "How many elements? ";
        cin >> numberRec;
       
        if (numberRec > SIZE || numberRec <= 0) {
            cout << "The number of elements should be less than 11 and"
                 << " greater than 0" << endl;
        }
    } while (numberRec > SIZE || numberRec <= 0);
   
    // Read data from  keyboard and populate arrays
    cout << "Enter the elements: ";
    for (int i = 0; i < numberRec; i++) {
        cin >> numberList[i];
    }
   
    // call the selection sort function
    SelectionSort(numberList, numberRec);
   
    // Display the sorted array
    cout << "The selected array is : ";
    for (int i = 0; i < numberRec; i++) {
        cout << numberList[i] << " ";
    }
    cout << "endl";
   
    return 0;
}

/* This function accepts an integer array and the size of the array, which it
then uses to sort the array using selection sort and stores it in ascending 
order, swapping the smallest found value with the current position of the 
index in the array.*/
void SelectionSort(int numbers[], int size) {
    // Runs through each element of the array one by one
    for (int i = 0; i < size - 1; i++) {
        // Assumes that the first value of the array is the minimum
        int minIndex = i;
        
        // Iterates through the array to find a lower value
        for (int j = i + 1; j < size; j++) {
            if (numbers[j] < numbers[minIndex]) {
                // Update the index with the new smallest element
                minIndex = j;
            }
        }
        
        // If a new minimum value is found, it is swapped with the first element 
        // of the unsorted part of the array
        if (minIndex != i) {
            int temp = numbers[i];
            numbers[i] = numbers[minIndex];
            numbers[minIndex] = temp;
        }
    }
}
