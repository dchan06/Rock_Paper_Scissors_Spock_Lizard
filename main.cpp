#include <iostream>
#include <random>
#include <ctime>

using namespace std;

//Checks if the input is valid
bool ValidInput(string * m, const string input, const int number) {
    for (int i = 0; i < number; i++) {
        if (input == m[i]){
            return true;
        }
    }
    return false;
}

int RandomMove () {
    unsigned seed = time(0);
    //Generates a random number that does not have a sequence
    mt19937 generator(seed);

    uniform_int_distribution<int> distribution(0, 2);

    //Returns the number
    return distribution(generator);
}

void Result (const string input, const string *moves, int * s, int * d) {
    int result = 0, computer_Move = RandomMove();

    cout << input <<"(YOU) VS " << *(moves+computer_Move) << "(COMPUTER)" << endl;

    // 0 = draw, 1 = computer win, 2 = player win
    if (input == "ROCK") {
        switch (computer_Move) {
            case 0 : result = 0; break;
            case 1 : result = 1; break;
            case 2 : result = 2; break;
            case 3 : result = 1; break;
            case 4 : result = 2; break;
            default: result = 0; break;
        }
    }
    else if (input == "PAPER") {
        switch (computer_Move) {
            case 0 : result = 2; break;
            case 1 : result = 0; break;
            case 2 : result = 1; break;
            case 3 : result = 2; break;
            case 4 : result = 1; break;
            default: result = 0; break;
        }
    }
    else if (input == "SCISSORS") {
        switch (computer_Move) {
            case 0 : result = 1; break;
            case 1 : result = 2; break;
            case 2 : result = 0; break;
            case 3 : result = 1; break;
            case 4 : result = 2; break;
            default: result = 0; break;
        }
    }
    else if (input == "SPOCK") {
        switch (computer_Move) {
            case 0 : result = 2; break;
            case 1 : result = 1; break;
            case 2 : result = 2; break;
            case 3 : result = 0; break;
            case 4 : result = 1; break;
            default: result = 0; break;
        }
    }
    else if (input == "LIZARD") {
        switch (computer_Move) {
            case 0 : result = 1; break;
            case 1 : result = 2; break;
            case 2 : result = 1; break;
            case 3 : result = 2; break;
            case 4 : result = 0; break;
            default: result = 0; break;
        }
    }
    else {
        cout << "Error";
        return;
    }

    switch (result) {
        case 0 : cout << "Draw" << endl;
        *d += 1;
        break;
        case 1 : cout << "YOU LOSE" << endl;
        break;
        case 2 : cout << "YOU WIN" << endl;
        *s += 1;
        break;
        default: cout << "Error"; break;
    }
}

int main() {
    const int num = 5;
    string moves[num] = {"ROCK", "PAPER", "SCISSORS", "SPOCK", "LIZARD"};
    int round = 1, score = 0, draws = 0;
    string input, round_Input;
    bool round_Start = true;

    while (round_Start) {

        //output the round number
        cout << "\nRound " << round << endl;

        //Loops requesting player to input a move if the move is invalid it will ask for an input again
        do {
            //Gets the user's input
            cout << "Input your move (ROCK/PAPER/SCISSORS/SPOCK/LIZARD): ";
            cin >> input;

            //While loop that changes the characters in the input to capital letters
            for (int i = 0; i < input.length(); i++) {

                //If it is in lower case
                if (islower(input[i])) {
                    //Make it upper case
                    input[i] = toupper(input[i]);
                }
                //All the inputs will be read as fully upper-cased words
            }
            //Calls the function to check if the input is valid and outputs an error if it is invalid
            if (!ValidInput(moves, input, num)) {
                cout << "Your move is invalid" << endl;
            }
            //Repeats the loop if the input is not valid
        }while (!ValidInput(moves, input, num));       //The loop continues as long as the input is invalid

        Result(input, moves, &score, &draws);
        cout << "Your score: "<< score << "\tComputer's score: " << round - score - draws << "\tDraws: " << draws << endl;
        cout << "\nWould you like to play again? (Y/N): ";
        cin >> round_Input;

        if (round_Input == "Y") {
            round += 1;
            round_Start = true;
        }
        else if (round_Input == "N") {
            cout << "Thanks for playing!";
            round_Start = false;
            return 0;
        }
        else {
            cout << "Invalid input";
            round_Start = false;
            return 0;
        }
    }
}