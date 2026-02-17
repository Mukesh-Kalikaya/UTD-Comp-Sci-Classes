/* This program generates pseudorandom numbers by taking an input seed and 
outputs the pseudorandom numbers.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Define varibales
    unsigned int seed;
    
    // Ask the user for the seed
    cout << "Enter a seed for the random number generator: ";
    cin >> seed;

    // Seed RNG with user input
    srand(seed);
    
    // Outputs the first 5 pseudorandom numbers from the user input
    cout << "First 5 numbers (seed = user input): ";
    cout << rand() << ", ";
    cout << rand() << ", ";
    cout << rand() << ", ";
    cout << rand() << ", ";
    cout << rand() << endl;
    
    // Change seed to current time
    srand(time(0));
    
    // Outputs the next 5 pseudorandom numbers from the current time
    cout << "First 5 numbers (seed = current time): ";
    cout << rand() << ", ";
    cout << rand() << ", ";
    cout << rand() << ", ";
    cout << rand() << ", ";
    cout << rand() << endl;

    return 0;
}