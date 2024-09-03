#include <bits/stdc++.h>
#include "file_.h"
using namespace std;

int main() {
    int choice;
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    while (true) {
        cout << "***Multiplication Learning Game***"<<endl;
        cout << "1. Start Game"<<endl;
        cout << "2. Help"<<endl;
        cout << "3. Show High Score"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                showHelp();
                break;
            case 3:
                showHighScore();
                break;
            case 4:
                exitGame();
                return 0;
            default:
                cout << "Invalid option. Please select again."<<endl;
        }
    }
    return 0;
}
