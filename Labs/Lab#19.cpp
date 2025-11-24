/* This program fills a 10 by 8 two-dimensional array with random
numbers from 1 to 10 and then calcualtes the sum of the neighbors for
each array element. Each element can have up to four neighbors: above, 
below, left, and right. The program displays the sum for neighbors for
every position in the array.*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Constants
const int ROWS = 10;
const int COLUMNS = 8;

// Function prototypes
void fillArray(int arr[][8], int rows, int columns);
int findSumOfNeighbors(const int arr[][8], const int row, const int column, 
                       const int rows, const int columns);

int main() {
    // Define variables
    unsigned int seed;
    int array[ROWS][COLUMNS];

    // Get the seed
    cin >> seed;
    srand(seed);

    fillArray(array, ROWS, COLUMNS);
    
    // Loop to output the sum of the neighbors to the user
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLUMNS; c++) {
            int sum = findSumOfNeighbors(array, r, c, ROWS, COLUMNS);
            cout << "The sum of the neighbors of array[" << r << "][" << c
                 << "] is " << sum << "." << endl;
        }
    }

    return 0;
}

/* This function is used to fill a 10x8 array with random numbers from 1 to 10.
The function takes in 3 arguments: the array that needs to be filled in, the 
total number of rows and then the total number of columns.*/
void fillArray(int arr[][8], int rows, int columns) {
    // Loop to fill each element of the array with a random value
    // from 1 to 10
    for (int c = 0; c < columns; c++) {
        for (int r = 0; r < rows; r++) {
            arr[r][c] = (rand() % 10) + 1;
        } 
    }
}

/* This function takes in 5 arguments: a two dimensional array, the row index
of the element, the column index of the element, the total number of rows, and
the last argument is the total number of columns in the array.T his function then 
calculates the sum of all neighbors in all of the valid directions 
(up, down, left, and right) of a specific element in the array and then returns
the sum.*/
int findSumOfNeighbors(const int arr[][8], const int row, const int column, 
                       const int rows, const int columns) {
    // Define variables
    int sum = 0;

    // Add the values of the neighbor above
    if (row > 0) {
        sum += arr[row - 1][column];
    }
    // Add the values of the neighbor below
    if (row < rows - 1) {
        sum += arr[row + 1][column];
    }
    // Add the values of the neighbor to the left
    if (column > 0) {
        sum += arr[row][column - 1];
    }
    // Add the values of the neighbor to the right
    if (column < columns - 1) {
        sum += arr[row][column + 1];
    }

    // Return the sum
    return sum;
}