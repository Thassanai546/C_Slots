#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int balance = 200;
    int bet;
    int num1, num2, num3;
    char playAgain;

    srand(time(NULL)); // Number generator

    do {
        cout << "Current balance:" << balance << endl;

        if (balance < 1) {
            cout << "It might be time to go home..." << endl;
        }

        cout << "Enter bet amount: ";
        cin >> bet;

        if (bet > balance) {
            cout << "You don't have enough money to make that bet." << endl;
            continue;
        }

        num1 = rand() % 10 + 1; // Generate random numbers
        num2 = rand() % 10 + 1;
        num3 = rand() % 10 + 1;

        cout << num1 << " " << num2 << " " << num3 << endl;

        if (num1 == num2 && num2 == num3) { // All three numbers are the same
            if (num1 == 7) {
                balance += bet * 25;
                cout << "JACKPOT! You won " << bet * 5 << endl;
            }
            else {
                balance += bet * 10;
                cout << "JACKPOT! You won " << bet * 10 << endl;
            }
        }
        else if (num1 == num2 || num1 == num3 || num2 == num3) { // Two numbers are the same
            balance += bet * 3;
            cout << "Two of a kind! You won " << bet * 3 << endl;
        }
        else { // No numbers are the same
            balance -= bet;
            cout << "Sorry, you lost " << bet << endl;
        }

        cout << "Play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing! Your final balance is " << balance << endl;

    return 0;
}

/*
So we roll the dice
See where they may fall
Come on, why don't we spin the wheel
See whom it may call
To give into temptation
To win it, or maybe lose it all
Who knows where the whims of fate may lead us - Shoji Meguro
*/