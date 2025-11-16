#ifndef HELPER_H
#define HELPER_H

#include <iostream>
using namespace std;
#include "cell.h"

struct corr {
    int row, col;
    corr(int r = -1, int c = -1) : row(r), col(c) {}
};

inline bool isEqual(corr a, corr b) {
    return a.row == b.row && a.col == b.col;
}

inline bool inBounds(corr c, int ROW, int COL) {
    return c.row >= 0 && c.row < ROW && c.col >= 0 && c.col < COL;
}

void clearMaze(vector<vector<Cell>>& maze, int ROW, int COL){
    for(vector<Cell>& row : maze){
        for (Cell& cell : row)
        {
            cell.clear();
        }
    }
}

void printMaze(corr start, corr goal, vector<vector<Cell>>& maze, int ROW, int COL) {
    for (int r = 0; r < ROW; r++) {
        
        // Print NORTH walls
        for (int c = 0; c < COL; c++) {
            cout << "+";
            if (maze[r][c].isWall(0))
                cout << "---";
            else
                cout << "   ";
        }
        cout << "+\n";

        // Print WEST walls + cell contents
        for (int c = 0; c < COL; c++) {

            // West wall
            if (maze[r][c].isWall(3))
                cout << "|";
            else
                cout << " ";

            // Cell content
            if (r == start.row && c == start.col)
                cout << " S ";
            else if (r == goal.row && c == goal.col)
                cout << " G ";
            else if (maze[r][c].isPath())        // final shortest path
                cout << " ^ ";
            else if (maze[r][c].isExplored())    // explored but not final path
                cout << " * ";
            else
                cout << " . ";
        }

        // Rightmost wall
        cout << "|\n";
    }

    // Bottom border
    for (int c = 0; c < COL; c++) {
        cout << "+";
        if (maze[ROW-1][c].isWall(1))
            cout << "---";
        else
            cout << "   ";
    }
    cout << "+\n";
}

#endif