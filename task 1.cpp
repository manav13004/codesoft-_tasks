#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int number, guess;

    // Generate random number
    srand(time(0));
    number = rand() % 100 + 1;

    cout << "Guess the number between 1 and 100!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > number) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < number) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed the correct number." << endl;
        }

    } while (guess != number);

    return 0;
}