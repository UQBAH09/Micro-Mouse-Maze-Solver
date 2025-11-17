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
            cell.setDistance(-1);
        }
    }
}

void printMaze(corr start, corr goal, vector<vector<Cell>>& maze, int ROW, int COL) {
    
}

#endif