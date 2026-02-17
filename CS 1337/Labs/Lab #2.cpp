/* This program does a binary search to find a specifc element in a sorted 
array. It asks the user for a search key and then uses the binarySearch 
function to narrow down the search range by half during each iteration. The 
program then displays the total number of iterations that were performed and 
then provides the index of the element of the search key if it was found or 
a message that says that the search key was not found if it isn't found after 
all of the iterations through the list. */
#include <iostream>
using namespace std;

// Function Prototype
int binarySearch(int list[], int key, int low, int high);

int main() {
    // Initialize array
    int list[] = {2, 4, 7, 10, 11, 28, 34, 45, 50, 59, 60, 66, 69, 70, 75, 89, 95};
    // Define variables
    int key, first = 0, last = 16;
    
    // Get the target value from the user
    cout << "Enter the element to search: ";
    cin >> key;

    // Use the binary search function and store the return value in the
    // variable i
    int i = binarySearch(list, key, first, last);
    
    // If the function returns something other than -1, the key was found and
    // is then outputted to the user
    if (i != -1) {
        cout << key << " is at index " << i << endl;
    }
    
    return 0;
}

int binarySearch(int list[], int key, int low, int high) {
    // Define the variable to track the amount of iterations
    int count = 0;
    
    // Keep searching the array until the low value has not passed the high
    // value or until the key has been found
    while (low <= high) {
        // Increment the count at the beginning of every step
        count ++;
        
        // Calculate the middle index of the range
        int mid = (low + high) / 2;
        
        // Check the list and see if the middle element is the one that holds
        // the element that the user wants to find
        if (list[mid] == key) {
            // If the key has been found, output the following statement to the 
            // user as well as return the value
            cout << "It takes "<< count << " iterations to find the key " << key 
                 << endl;
            return mid;
        // If they key was not found, check to see if the key is smaller than
        // the middle element
        } else if (list[mid] > key) {
            high = mid - 1;
        // If they key was not found and is not smaller than the middle element,
        // check to see if the key is bigger than the middle element
        } else {
            low = mid + 1;
        }
    }
    
    // Output this following statement if the key was not found after all of the
    // iterations and return -1 to trigger an if-statement in the main() function
    cout << "After  "<< count << " iterations "<< key << " is not found!" 
         << endl;
    return -1;
}
