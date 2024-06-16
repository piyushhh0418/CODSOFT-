#include <iostream>

using namespace std;

const int Size = 3;
char board [Size] [Size];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void displayBoard() {
    cout << "  0 1 2\n";
    for (int i = 0; i < Size; ++i) {
        cout << i << " ";
        for (int j = 0; j < Size; ++j) {
            cout << board[i][j];
            if (j < Size - 1) cout << "|";
        }
        cout << "\n";
        if (i < Size - 1) cout << "  -+-+-\n";
    }
}

bool isMoveValid(int row, int col) {
    return (row >= 0 && row < Size && col >= 0 && col < Size && board[row][col] == ' ');
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < Size; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    initializeBoard();
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        displayBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;
            gameWon = checkWin();
            gameDraw = checkDraw();
            if (!gameWon && !gameDraw) {
                switchPlayer();
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    displayBoard();
    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!\n";
    } else if (gameDraw) {
        cout << "The game is a draw!\n";
    }
}

int main() {
    char playAgain = 'Y';
    while (playAgain == 'Y' || playAgain == 'y') {
        playGame();
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    }
    return 0;
}
