/*
 * File: KnightsTour.cpp
 * ---------------------
 * This program find a knight's tour on an N x M chessboard.
 */

#include <iostream>
#include <iomanip>
#include "grid.h"

using namespace std;

/* Function prototypes */

void solveKnightsTour(int n, int m);
void displayBoard(Grid<int> & board);
bool findKnightsTour(Grid<int> & board, int row, int col, int seq);

/* Test program */

int test2() {
   solveKnightsTour(8, 8);
   return 0;
}

/*
 * Function: solveKnightsTour
 * Usage: solveKnightsTour(n, m);
 * ------------------------------
 * Solves the knight's tour problem for a n x m chessboard.
 */

void solveKnightsTour(int n, int m) {
   Grid<int> board(n, m);
   if (findKnightsTour(board, 0, 0, 1)) {
      displayBoard(board);
   } else {
      cout << "No tour exists for this board." << endl;
   }
}

/*
 * Function: displayBoard
 * Usage: displayBoard(board);
 * ---------------------------
 * Displays each of the squares in the board along with its sequence
 * number in the tour.
 */

void displayBoard(Grid<int> & board) {
   for (int i = board.numRows() - 1; i >= 0; i--) {
      for (int j = 0; j < board.numCols(); j++) {
         cout << " " << setw(2) << board[i][j];
      }
      cout << endl;
   }
}

/*
 * Function: findKnightsTour
 * Usage: flag = findKnightsTour(board, row, col, seq);
 * ----------------------------------------------------
 * This function looks for a tour on the board, starting at
 * the position indicated by row and col. The seq parameter is
 * the sequence number of this move and is needed to keep
 * track of the steps on the tour. The function returns true
 * if a tour is found and false otherwise.
 *
 * This function begins by checking for three simple cases:
 *
 * 1. The position is off the board.
 * 2. The position has been previously visited.
 * 3. The tour is complete.
 *
 * In the first two cases, there can be no tour that begins
 * from that position on the board. In the last case, the
 * function can immediately return true.
 *
 * If the simple cases do not apply, the function marks the
 * current square and then tries all possible moves. If it
 * finds a tour from the resulting position, the function
 * returns true to the next highest level. If no moves lead
 * to a tour, the function must back out of this move and try
 * again at a higher level of the recursion.
 *
 * The for loops in this implementation are a little tricky.
 * They compute the row and column offsets for the next position by
 * noting that the row and column offsets add to 3 (either +1 and +2
 * or +2 and +1) and you need all four possible sign combinations.
 */


// Use enumeration type to represent 8 directions
enum dir {
    SE,
    ES,
    EN,
    NE,
    NW,
    WN,
    WS,
    SW,
};

dir operator++(dir & move, int) {
    dir old = move;
    move = dir(old + 1);
    return old;
}

// The result of a row change after each move
int getRow(dir move, int row) {
    int newRow = row;;
    switch (move) {
        case SE:
        case SW:
            newRow += 2;
            break;
        case NW:
        case NE:
            newRow -= 2;
            break;
        case WS:
        case ES:
            newRow += 1;
            break;
        case WN:
        case EN:
            newRow -= 1;
            break;
        default:
            break;
    }
    return newRow;
}
// The result of a column change after each move
int getCol(dir move, int col) {
    int newCol = col;
    switch (move) {
        case NW:
        case SW:
            newCol -= 1;
            break;
        case NE:
        case SE:
            newCol += 1;
            break;
        case EN:
        case ES:
            newCol += 2;
            break;
        case WN:
        case WS:
            newCol -= 2;
            break;
        default:
            break;
    }
    return newCol;
}

bool findKnightsTour(Grid<int> & board, int row, int col, int seq) {

    //TODO
    // the first time, to initialize the board
    if (seq == 1) {
        for (int r = 0; r < board.numRows(); r++) {
            for (int c = 0; c < board.numCols(); c++) {
                board[r][c] = 0;
            }
        }
    }

    // 3 simple cases
    // 1. The position is off the board.
    if (!board.inBounds(row, col)) {
        return false;
    }
    // 2. The position has been previously visited.
    if (board[row][col] != 0) {
        return false;
    }
    // 3. The tour is complete.
    if (board[row][col] == 0 && seq == board.numRows() * board.numCols()) {
        board[row][col] = seq;
        return true;
    }

    // simple cases do not apply
    board[row][col] = seq;  // mark current position
    // iterate over each possible movement
    for (dir move = SE; move <= SW; move++) {
        int nextRow = getRow(move, row);
        int nextCol = getCol(move, col);
        // Next position meet the requirement
        if (board.inBounds(nextRow, nextCol) && board[nextRow][nextCol] == 0) {
            // recursion, seq + 1
            if (findKnightsTour(board, nextRow, nextCol, seq + 1)) {
                return true;
            }
        }
    }
    // backtrack, cancel the mark
    board[row][col] = 0;
    return false;
}
