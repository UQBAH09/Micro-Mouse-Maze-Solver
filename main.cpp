#include <iostream>
#include <vector>
#include "BFS.cpp"

using namespace std;

#define ROW 5
#define COL 5
vector<vector<Cell>> maze = {
    // Row 0
    {
        Cell(true,  false, false, true ),   // (0,0) Start
        Cell(true,  false, false, false),   // (0,1)
        Cell(true,  true,  false, false),   // (0,2)
        Cell(true,  false, true,  false),   // (0,3)
        Cell(true,  false, true,  false)    // (0,4)
    },

    // Row 1
    {
        Cell(false, false, false, true ),   // (1,0)
        Cell(false, false, false, false),   // (1,1)
        Cell(true,  false, false, false),   // (1,2)
        Cell(false, true,  true,  false),   // (1,3)
        Cell(false, false, true,  false)    // (1,4)
    },

    // Row 2
    {
        Cell(false, true,  false, true ),   // (2,0)
        Cell(false, true, true,  false),   // (2,1)
        Cell(false, false, false, true ),   // (2,2)
        Cell(true,  false, false, false),   // (2,3)
        Cell(false, false, true,  false)    // (2,4)
    },

    // Row 3
    {
        Cell(true,  false, false, true ),   // (3,0)
        Cell(true, true,  false, false),   // (3,1)
        Cell(false,  true, true,  false),   // (3,2)
        Cell(false,  true, false, true ),   // (3,3)
        Cell(false, true, true,  false)    // (3,4)
    },

    // Row 4
    {
        Cell(false, true,  false, true ),   // (4,0)
        Cell(true,  true,  false, false),   // (4,1)
        Cell(true,  true,  false, false),   // (4,2)
        Cell(true,  true,  false, false),   // (4,3)
        Cell(true,  true,  true,  false)    // (4,4) Goal
    }
};

void printMaze(corr start, corr goal) {
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

int main() {
    corr start(0,0);
    corr goal(4,4);

    if (BFS(start, goal, maze, ROW, COL)){
        cout << "Path found!\n";
        printMaze(start,goal);
    }
    else
        cout << "No path.\n";

    return 0;
}
