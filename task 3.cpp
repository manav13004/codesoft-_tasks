#include <iostream>
using namespace std;

// Function to display the board
void displayBoard(char board[3][3]) {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return false;
        }
    }
    return true;
}

int main() {
    char playAgain;

    do {
        // Create the game board
        char board[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };

        char currentPlayer = 'X';
        int choice;
        bool gameOver = false;

        cout << "\n===== TIC-TAC-TOE GAME =====\n";

        while (!gameOver) {
            displayBoard(board);

            cout << "Player " << currentPlayer
                 << ", enter your move (1-9): ";
            cin >> choice;

            // Check if input is valid
            if (choice < 1 || choice > 9) {
                cout << "Invalid move! Please enter a number from 1 to 9.\n";
                continue;
            }

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            // Check if position is already occupied
            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "That position is already taken! Try again.\n";
                continue;
            }

            // Update board
            board[row][col] = currentPlayer;

            // Check for win
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! 🎉\n";
                gameOver = true;
            }

            // Check for draw
            else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                gameOver = true;
            }

            // Switch players
            else {
                if (currentPlayer == 'X')
                    currentPlayer = 'O';
                else
                    currentPlayer = 'X';
            }
        }

        // Ask to play again
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing Tic-Tac-Toe!\n";

    return 0;
}