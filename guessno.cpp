#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // seed the random number generator
    int number = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess = -1; // initialize the guess to an invalid value
    int guessAmount = 0; // count the number of guesses

    while (guess!= number) {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        guessAmount++;
        if(guess==number){
            cout<<"Congratulations!you guessed the right number"<<endl;
        }
        else if (guess < number) {
            cout << "Too low! Try again." << endl;
        } else if (guess > number) {
            cout << "Too high! Try again." << endl;
        }
    }

    cout << "Congratulations! You guessed the correct number in " << guessAmount << " attempts." << endl;

    return 0;
}