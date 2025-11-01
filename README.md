# Rock-Paper-Scissor
A fun and interactive Rock Paper Scissors game using C++. Play against the computer, test your luck and track your score. 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string getComputerChoice() {
    int random = rand() % 3;
    if (random == 0) return "rock";
    else if (random == 1) return "paper";
    else return "scissors";
}

string findWinner(const string& player, const string& computer) {
    if (player == computer) return "draw";
    if ((player == "rock" && computer == "scissors") ||
        (player == "paper" && computer == "rock") ||
        (player == "scissors" && computer == "paper"))
        return "player";
    else
        return "computer";
}

int main() {
    srand(time(0));
    int playerScore = 0, computerScore = 0;
    string playerChoice, computerChoice, result;
    char playAgain;

    cout << "=== ROCK - PAPER - SCISSORS ===\n";
    do {
        cout << "Your choice: ";
        cin >> playerChoice;
        for (auto &c : playerChoice) c = tolower(c);
        if (playerChoice != "rock" && playerChoice != "paper" && playerChoice != "scissors") {
            cout << "Invalid choice!\n";
            continue;
        }
        computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << "\n";
        result = findWinner(playerChoice, computerChoice);
        if (result == "player") {
            cout << "You win this round!\n";
            playerScore++;
        } else if (result == "computer") {
            cout << "Computer wins this round!\n";
            computerScore++;
        } else {
            cout << "It's a draw!\n";
        }
        cout << "Score → You: " << playerScore << " | Computer: " << computerScore << "\n";
        cout << "Play again? (y/n): ";
        cin >> playAgain;
        cout << "\n";
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Final Score → You: " << playerScore << " | Computer: " << computerScore << "\n";
    if (playerScore > computerScore) cout << "You are the champion!\n";
    else if (playerScore < computerScore) cout << "Computer wins the game!\n";
    else cout << "It's a tie!\n";
    return 0;
}
