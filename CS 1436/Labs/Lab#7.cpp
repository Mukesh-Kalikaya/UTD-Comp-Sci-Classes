/* This program will generate random numbers between
1 and 6 to simulate rolling a two sided die and then 
shows the result along with the result based on the game
craps.  */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int seed;
    
    // Generate the random dice values
    cin >> seed;
    srand(seed);
    
    // Randomize and assign values to the variables
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;
    int sum;
    
    // Output the randomized dice values
    cout << "Die 1: " << dice1 << endl;
    cout << "Die 2: " << dice2 << endl;
    
    // Sum of the dice.
    sum = dice1 + dice2;
    
    // Output the result of the dice roll
    if (sum == 7 || sum == 11) {
        cout << endl << "Player loses.";
    } else if (sum == 2 || sum == 3) {
        cout << endl << "Player wins.";
    } else if (sum == 12) {
        cout << endl << "Start over.";
    } else {
        cout << endl << "Keep rolling.";
    }
    
    return 0;
}