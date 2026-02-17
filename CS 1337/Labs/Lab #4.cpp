/* This program creates an array of numbers that are random and the size is 
based on how many the user wants. It then sorts these numbers from lowest to 
highest using Selection Sort and displays the sorted array to the user. */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE 100

void SelectionSort(int [], int size );
//void SelectionSort(int numbers[], int numbersSize);
int main() {
    int numberList[SIZE];
    int numberRec;
    int seed;

    // 
    cout << "How many elements? ";
    cin >> numberRec;

    // input validation
    while(numberRec > 100 || numberRec <= 0) {
        cout << "The number of elements should be less than " << SIZE + 1 
             << " or greater than 0" << endl;
        cout << "How many elements? ";
        cin >> numberRec;
    }
    
    // Random seed generator
    cout << "Enter a seed value: ";
    cin >> seed;
    srand(seed);
    
    cout << "The array after populating value is: " << endl;
    // Read data from keyboard and populate arrays

    // The loop fills the array with the random numbers
    for(int i = 0; i < numberRec; i++) {
        // Keeps the numbers between 0 and 49 
        numberList[i] = (rand() % 50);
        cout << setw(3) <<  numberList[i];
    }
    cout << endl;
    
    // call the selection sort function
    SelectionSort(numberList, numberRec);

    // Display the sorted array
    cout << "The sorted array is : " << endl;
    for (int i = 0; i < numberRec; i++) {
        cout << setw(3) << numberList[i];
    }
    cout << endl;

    return 0;
}

/* This function scans the list for the smallest available number and swaps it 
into its correct position by comparing the values at each index of the array.*/
void SelectionSort(int numbers[], int size) {
    // Moves the bounds between sorted and unsorted parts of the array
    for (int i = 0; i < size - 1; i++) {
        //Assumes that the first element is the lowest element in the array
        int minIndex = i;
        
        // Find index of smallest remaining element, current MinIndex
        for (int j = i + 1; j < size; j++) {
            if (numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swaps the lowest found element with the current position 'i'
        if (minIndex != i) {
            int temp = numbers[i];
            numbers[i] = numbers[minIndex];
            numbers[minIndex] = temp;
        }
    }
}
