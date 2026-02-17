/* This program generates two random single digit integer numbers and 
asks the user to enter the solution for the question and then compares 
that with the correct answer which is computed by the system. If the answers 
match, the user will receive a congratulatory message saying that the answer
is correct and a message that the answer is incorrect if it is incorrect.
Regardless of whether the answer is correct or wrong, the program will 
show the solution after the message.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Define the variables and get the seed
    unsigned int seed;
    int correctAnswer, userAnswer;
    int minuend, subtrahend;
    
    // Get the seed and RNG the seed
    cin >> seed; // seed = time(0);
    srand(seed);
    
    // Generates two random number between 0 to 9
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    
    // Check which number is the minuend and subtrahend
    if (num1 > num2) {
        minuend = num1;
        subtrahend = num2;
    } else {
        minuend = num2;
        subtrahend = num1;
    }
    
    // Compute the correct answwer
    correctAnswer = minuend - subtrahend;
    
    // Ask the user for the answer
    cout << "What is " << minuend << " - " << subtrahend << "? ";
    cin >> userAnswer;
    
    // Compare the answers and output a message accordingly
    if (userAnswer == correctAnswer) {
        cout << "Congratulations! That is correct!" << endl;
    } else {
        cout << "The answer is incorrect. Please try again." << endl;
    }
    
    // Show the solution regardless of the user's answer (correct or incorrect) 
    cout << minuend << " - " << subtrahend << " = " << correctAnswer << endl;

    return 0;
}