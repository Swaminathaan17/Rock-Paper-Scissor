#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

string getComputerChoice() {
    int random = rand() % 3;

    if (random == 0)
        return "rock";
    else if (random == 1)
        return "paper";
    else
        return "scissors";
}

string getCounterMove(string playerMove) {
    if (playerMove == "rock")
        return "paper";

    if (playerMove == "paper")
        return "scissors";

    return "rock";
}

string findWinner(const string& player, const string& computer) {
    if (player == computer)
        return "draw";

    if ((player == "rock" && computer == "scissors") ||
        (player == "paper" && computer == "rock") ||
        (player == "scissors" && computer == "paper"))
        return "player";

    return "computer";
}

int main() {
    srand(time(0));

    string username;
    char playAgain;

    cout << "=================================\n";
    cout << "     ROCK PAPER SCISSORS 🎮\n";
    cout << "=================================\n\n";

    cout << "Enter Username: ";
    getline(cin >> ws, username);

    cout << "\nWelcome, " << username << "!\n";
    cout << "Good luck beating the AI. 🎯\n";

    do {
        string matchInput;
        string difficultyInput;

        int winsNeeded;
        int difficulty;

        int playerScore = 0;
        int computerScore = 0;
        int roundNumber = 1;

        string playerChoice;
        string computerChoice;
        string result;

        cout << "\nChoose Match Type:\n";
        cout << "1. Best of 1\n";
        cout << "3. Best of 3\n";
        cout << "5. Best of 5\n";

        while (true) {
            cout << "Enter choice: ";
            cin >> matchInput;

            for (auto& c : matchInput)
                c = tolower(c);

            if (matchInput == "1" ||
                matchInput == "one" ||
                matchInput == "bestof1" ||
                matchInput == "best1") {

                winsNeeded = 1;
                break;
            }
            else if (matchInput == "3" ||
                     matchInput == "three" ||
                     matchInput == "bestof3" ||
                     matchInput == "best3") {

                winsNeeded = 2;
                break;
            }
            else if (matchInput == "5" ||
                     matchInput == "five" ||
                     matchInput == "bestof5" ||
                     matchInput == "best5") {

                winsNeeded = 3;
                break;
            }

            cout << "❌ Invalid match type. Try again.\n";
        }

        cout << "\nChoose Difficulty:\n";
        cout << "1. Easy 😊\n";
        cout << "2. Medium 😎\n";
        cout << "3. Hard 😈\n";

        while (true) {
            cout << "Enter choice: ";
            cin >> difficultyInput;

            for (auto& c : difficultyInput)
                c = tolower(c);

            if (difficultyInput == "1" ||
                difficultyInput == "easy") {

                difficulty = 1;
                break;
            }
            else if (difficultyInput == "2" ||
                     difficultyInput == "medium") {

                difficulty = 2;
                break;
            }
            else if (difficultyInput == "3" ||
                     difficultyInput == "hard") {

                difficulty = 3;
                break;
            }

            cout << "❌ Invalid difficulty. Try again.\n";
        }

        while (playerScore < winsNeeded &&
               computerScore < winsNeeded) {

            cout << "\n========== ROUND "
                 << roundNumber
                 << " ==========\n";

            cout << "Your choice (rock/paper/scissors): ";
            cin >> playerChoice;

            for (auto& c : playerChoice)
                c = tolower(c);

            if (playerChoice == "r")
                playerChoice = "rock";
            else if (playerChoice == "p")
                playerChoice = "paper";
            else if (playerChoice == "s")
                playerChoice = "scissors";

            if (playerChoice != "rock" &&
                playerChoice != "paper" &&
                playerChoice != "scissors") {

                cout << "❌ Invalid choice! Try again.\n";
                continue;
            }

            if (difficulty == 1) {
                computerChoice = getComputerChoice();
            }
            else if (difficulty == 2) {
                if (rand() % 2 == 0)
                    computerChoice = getComputerChoice();
                else
                    computerChoice = getCounterMove(playerChoice);
            }
            else {
                int chance = rand() % 100;

                if (chance < 95)
                    computerChoice = getCounterMove(playerChoice);
                else
                    computerChoice = getComputerChoice();
            }

            cout << "\nComputer chose: "
                 << computerChoice << "\n";

            if (difficulty == 3) {
                string taunts[] = {
                    "🤖 Predictable.",
                    "🤖 I saw that coming.",
                    "🤖 Too easy.",
                    "🤖 Try harder.",
                    "🤖 Is that your best move?",
                    "🤖 My circuits are bored.",
                    "🤖 Humans are fascinating.",
                    "🤖 Calculating your defeat...",
                    "🤖 Another expected move.",
                    "🤖 Better luck next round."
                };

                cout << taunts[rand() % 10] << "\n";
            }

            result = findWinner(playerChoice, computerChoice);

            if (result == "player") {
                cout << "✅ You win this round!\n";
                playerScore++;
            }
            else if (result == "computer") {
                cout << "❌ Computer wins this round!\n";
                computerScore++;
            }
            else {
                cout << "🤝 It's a draw!\n";
            }

            cout << "\n========== SCORE ==========\n";
            cout << username << ": " << playerScore << "\n";
            cout << "Computer: " << computerScore << "\n";
            cout << "===========================\n";

            roundNumber++;
        }

        cout << "\n===============================\n";
        cout << "         MATCH OVER\n";
        cout << "===============================\n";

        if (playerScore > computerScore) {
            cout << "🏆 Congratulations, "
                 << username
                 << "! You won the match!\n";
        }
        else {
            cout << "🤖 Computer wins the match!\n";
        }

        cout << "\nPlay Again? (y/n): ";
        cin >> playAgain;

    } while (tolower(playAgain) == 'y');

    cout << "\nThanks for playing, "
         << username
         << "! 👋\n";

    return 0;
}
