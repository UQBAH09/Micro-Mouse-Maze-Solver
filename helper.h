#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include "cell.h"
using namespace std;

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
            cell.setDistance(-1);
        }
    }
}

void printMaze(corr start, corr goal, const vector<vector<Cell>>& maze, int ROW, int COL) 
{
    cout << "\n";
    cout << "Legend: S=Start  G=Goal  P=Path  E=Explored  .=Unvisited\n\n";

    for (int r = 0; r < ROW; r++) {

        // TOP WALLS OF ROW
        for (int c = 0; c < COL; c++) {
            cout << "+";
            if (maze[r][c].isWall(0)) cout << "---"; // north wall
            else cout << "   ";
        }
        cout << "+\n";

        //LEFT WALL + CELL CONTENT
        for (int c = 0; c < COL; c++) {

            // Left wall
            if (maze[r][c].isWall(3)) cout << "|";  // west wall
            else cout << " ";

            // Cell content
            if (r == start.row && c == start.col) cout << " S ";
            else if (r == goal.row && c == goal.col) cout << " G ";
            else if (maze[r][c].isPath()) cout << " P ";
            else if (maze[r][c].isExplored()) cout << " E ";
            else cout << " . ";

            // Last column right wall
            if (c == COL - 1) {
                if (maze[r][c].isWall(2)) cout << "|";  // east wall
                else cout << " ";
            }
        }
        cout << "\n";
    }

    //  BOTTOM WALL OF LAST ROW
    for (int c = 0; c < COL; c++) {
        cout << "+";
        if (maze[ROW-1][c].isWall(1)) cout << "---"; // south wall
        else cout << "   ";
    }
    cout << "+\n\n";
}

void printDistance(const vector<vector<Cell>>& maze, int ROW, int COL) 
{
    cout << "\n";

    for (int r = 0; r < ROW; r++) {

        // TOP WALLS OF ROW
        for (int c = 0; c < COL; c++) {
            cout << "+";
            if (maze[r][c].isWall(0)) cout << "---";  
            else cout << "   ";
        }
        cout << "+\n";

        // LEFT WALL + CELL CONTENT
        for (int c = 0; c < COL; c++) {

            // Left wall
            if (maze[r][c].isWall(3)) cout << "|";
            else cout << " ";

            // Distance Formatting (manual)
            int d = maze[r][c].getDisatance();

            if (d < 0) {
                cout << "   ";                 // unexplored
            }
            else if (d < 10) {
                cout << " " << d << " ";       // 1 digit → " d "
            }
            else if (d < 100) {
                cout << " " << d;              // 2 digits → " dd"
            }
            else {
                // just print the actual 3-digit number 
                cout << d;
            }

            // Right wall of last column
            if (c == COL - 1) {
                if (maze[r][c].isWall(2)) cout << "|";
                else cout << " ";
            }
        }
        cout << "\n";
    }

    // BOTTOM WALL 
    for (int c = 0; c < COL; c++) {
        cout << "+";
        if (maze[ROW - 1][c].isWall(1)) cout << "---";
        else cout << "   ";
    }
    cout << "+\n\n";
}









#endif