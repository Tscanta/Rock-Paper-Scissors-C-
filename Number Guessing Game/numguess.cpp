#include <iostream>
#include <ctime>

//THE MAIN PROGRAM
int main() {
    srand(time(NULL));
    using namespace std;
    char choicereplay;

    //Randomizer
    do {
        int tries = 0;
        int guess;

        int num = (rand() % 100) + 1;

        cout << "------THE GUESSING GAME-------" << '\n';

        do {
            cout << "Enter your guess between 1 to 100: " << '\n';
            cin >> guess;

            //if you enter a string or a character value
            while (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "INVALID INPUT. Please enter an integer value.";
                cin >> guess;
            }

            tries++;

            if (guess > num) {
                cout << "Too hot!" << '\n';
            }
            else if (guess < num) {
                cout << "Too cold!" << '\n';
            }
            else {
                cout << "Bingo! thats the word, congrats! It took you " << tries << " tries to get it." << '\n';
                cout << "Play again and aim for a new high score";
            }

        }while (guess != num);
        cout << "Do you want to play again? (press y)";
        cin >> choicereplay;
    }while (choicereplay == 'Y' || choicereplay == 'y');

    cout << "Thanks for playing. Go home.";
    return 0;
}