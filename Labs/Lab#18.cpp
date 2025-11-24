/* This program simulates rolling a six sided die. The program does this as 
many times as the user asked for the program to do so and then it stores 
which face is rolled how many times and then it displays the frequency 
and the percentage for each face.*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Function Prototypes
void dispFreqAndPercentages(const unsigned int freq[], const unsigned int rolls);

int main() {
    // Define variables
    unsigned int seed;
    unsigned int rolls;
    unsigned int frequency[7] = {0};
    int roll;

    // Get the seed from the user
    cin >> seed;
    srand(seed);

    // Get the amount of times the user wants to roll the die
    cout << "Please enter the number of times to roll the die: ";
    cin >> rolls;
    cout << endl;

    // Randomize
    for (unsigned int i = 0; i < rolls; i++) {
        roll = (rand() % 6) + 1;
        frequency[roll]++;
    }

    // Use the function if the amount of rolls is greater than 0
    if (rolls > 0) {
        dispFreqAndPercentages(frequency, rolls);
    }

    return 0;
}

/* This function has two parameters: one that contains the frequency and 
one which contains the total number of rolls. This function then displays 
the chart which shows how frequent each face was rolled in the count that 
the user has specified and it also shows the percentage corresponding to 
the frequency.*/
void dispFreqAndPercentages(const unsigned int freq[], const unsigned int rolls) {
    cout << fixed << setprecision(1);

    for (int face = 1; face <= 6; face++) {
        double percent = (static_cast<double>(freq[face]) / rolls) * 100;

        cout << "Face #" << face << ": " << "Frequency:" << setw(6)
             << freq[face] << " Percentage:" << setw(6) << percent << endl;
    }
}