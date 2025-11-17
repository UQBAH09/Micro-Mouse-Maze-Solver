#include <iostream>
#include <vector>
#include "BFS.cpp"
#include "DFS.cpp"
#include "FFS.cpp"

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

int main() {
    corr start(0,0);
    corr goal(4,4);
    
    // Orignal Maze
    cout << "Orignal Maze: " << endl;
    printMaze(start,goal, maze, ROW, COL);

    // BFS
    cout << "BFS: " << endl;
    if (BFS(start, goal, maze, ROW, COL)){
        cout << "Path found!\n";
        printMaze(start,goal, maze, ROW, COL);
    }
    else cout << "No path.\n";

    //clearing maze
    clearMaze(maze, ROW, COL);

    //DFS
    cout << "DFS: " << endl;
    if (DFS(start, goal, maze, ROW, COL)){
        cout << "Path found!\n";
        printMaze(start,goal, maze, ROW, COL);
    }
    else cout << "No path.\n";

    //clearing maze
    clearMaze(maze, ROW, COL);

    //FFS
    cout << "FFS: " << endl;
    if (FFS(start, goal, maze, ROW, COL)){
        cout << "Path found!\n";
        printMaze(start,goal, maze, ROW, COL);
    }
    else cout << "No path.\n";

    return 0;
}
