#include <iostream>
#include <cctype>
#include <ctime>

using namespace std;

char getUserChoice();
char getCompChoice();
void showChoice(char choice);
void chooseWinner(char player, char comp);

//THE MAIN FUNCTION
int main() {
    char player;
    char comp;
    char choicereplay;

    do {
        player = getUserChoice();
        cout << "Your Choice: ";
        showChoice(player);

        comp = getCompChoice();
        cout << "Computer's Choice: ";
        showChoice(comp);

        chooseWinner(player,comp);

        cout << "Do you want to play again?\n";
        cout << "'Y' for yes | 'N' for no: \n";
        cin >> choicereplay;
        cin.ignore();
    }while (choicereplay == 'Y' || choicereplay == 'y');

    cout << "Thanks for playing!";

    return 0;
}

//GETTING USER CHOICE
char getUserChoice()
{
    char player;
    cout << "---------ROCK PAPER SCISSORS SHOOT!!!-----------\n";
    do
    {
        cout << "ENTER YOUR CHOICE\n";
        cout << "Press 'R' for ROCK\n";
        cout << "Press 'P' for PAPER\n";
        cout << "Press 'S' for SCISSORS\n";
        cin >> player;
        cin.ignore();
        player = toupper(player);

        //Clear any previous errors
        cin.clear();
        cin.ignore(1000, '\n'); //Discards bad input

        //Cant enter another characters
        if(player != 'R' && player != 'P' && player != 'S') {
            cout << "Invalid input. Enter only R, P, or S. \n";
        }

    }while (player != 'R' && player != 'P' && player != 'S');  //it will only accept these values

    return player;
}

//GETTING THE COMPUTERS CHOICE
char getCompChoice()
{
    srand(time(NULL));
    int num = rand() % 3 + 1;
    switch (num){
        case 1: return 'R';
        case 2: return 'P';
        case 3: return 'S';
    }
    return 0;
}

//SHOWING WHAT CHOICES HAVE BEEN CHOOSEN
void showChoice(char choice) {
    switch (choice) {
        case 'R': cout << "ROCK\n";
            break;
        case 'P': cout << "PAPER\n";
            break;
        case 'S': cout << "SCISSORS\n";
            break;
    }
}

//CHOOSING OUR WINNER
void chooseWinner(char player, char comp) {
    switch (player) {
        case 'R':
            if (comp == 'R')
            {
                cout << "Its a tie";
            }
            else if (comp == 'P')
            {
                cout << "You lose :(";
            }
            else
            {
                cout << "You win :)";
            }
            break;

        case 'P':
            if (comp == 'P')
            {
                cout << "Its a tie";
            }
            else if (comp == 'S')
            {
                cout << "You lose :(";
            }
            else
            {
                cout << "You win :)";
            }
            break;

        case 'S':
            if (comp == 'S')
            {
                cout << "Its a tie";
            }
            else if (comp == 'R')
            {
                cout << "You lose :(";
            }
            else
            {
                cout << "You win :)";
            }
            break;

        default: cout << "Invalid Input";
            break;
    }
}