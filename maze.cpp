#include <iostream>
#include <vector>
#include "BFS.cpp"
#include "DFS.cpp"
#include "FFS.cpp"
using namespace std;

vector<vector<Cell>> maze = {
    // Row 0 - Start with multiple options
    {
        Cell(true,false,true,true),    // (0,0) Start - can go SOUTH and EAST
        Cell(true,true,false,true),    // (0,1)
        Cell(true,true,false,false),   // (0,2)
        Cell(true,true,true,false),    // (0,3)
        Cell(true,true,false,true),    // (0,4)
        Cell(true,true,false,false),   // (0,5)
        Cell(true,true,true,false),    // (0,6)
        Cell(true,true,false,true),    // (0,7)
        Cell(true,true,false,false),   // (0,8)
        Cell(true,true,true,false),    // (0,9)
        Cell(true,true,false,true),    // (0,10)
        Cell(true,true,false,false),   // (0,11)
        Cell(true,true,true,false),    // (0,12)
        Cell(true,true,false,true),    // (0,13)
        Cell(true,true,true,false)     // (0,14)
    },
    // Row 1 - Multiple branches
    {
        Cell(false,true,false,true),   // (1,0) - can go NORTH, SOUTH, EAST
        Cell(true,false,true,false),   // (1,1)
        Cell(true,true,false,true),    // (1,2)
        Cell(true,false,false,false),  // (1,3)
        Cell(true,true,true,false),    // (1,4)
        Cell(true,true,false,true),    // (1,5)
        Cell(true,false,false,false),  // (1,6)
        Cell(true,true,true,false),    // (1,7)
        Cell(true,true,false,true),    // (1,8)
        Cell(true,false,false,false),  // (1,9)
        Cell(true,true,true,false),    // (1,10)
        Cell(true,true,false,true),    // (1,11)
        Cell(true,false,false,false),  // (1,12)
        Cell(true,true,true,false),    // (1,13)
        Cell(true,false,true,false)    // (1,14)
    },
    // Row 2 - Dead ends and paths
    {
        Cell(false,false,true,true),   // (2,0) - can go NORTH, SOUTH, EAST
        Cell(false,true,false,true),   // (2,1)
        Cell(true,false,true,false),   // (2,2)
        Cell(false,true,false,true),   // (2,3)
        Cell(true,false,false,false),  // (2,4)
        Cell(true,true,true,false),    // (2,5)
        Cell(false,true,false,true),   // (2,6)
        Cell(true,false,false,false),  // (2,7)
        Cell(true,true,true,false),    // (2,8)
        Cell(false,true,false,true),   // (2,9)
        Cell(true,false,false,false),  // (2,10)
        Cell(true,true,true,false),    // (2,11)
        Cell(false,true,false,true),   // (2,12)
        Cell(true,false,false,false),  // (2,13)
        Cell(false,true,true,false)    // (2,14)
    },
    // Row 3 - Maze continues
    {
        Cell(false,true,false,true),   // (3,0)
        Cell(true,false,true,false),   // (3,1)
        Cell(false,true,false,true),   // (3,2)
        Cell(true,false,false,false),  // (3,3)
        Cell(false,true,true,false),   // (3,4)
        Cell(true,false,false,true),   // (3,5)
        Cell(true,false,false,false),  // (3,6)
        Cell(false,true,true,false),   // (3,7)
        Cell(true,false,false,true),   // (3,8)
        Cell(true,false,false,false),  // (3,9)
        Cell(false,true,true,false),   // (3,10)
        Cell(true,false,false,true),   // (3,11)
        Cell(true,false,false,false),  // (3,12)
        Cell(false,true,true,false),   // (3,13)
        Cell(true,false,true,false)    // (3,14)
    },
    // Row 4 - More complexity
    {
        Cell(false,false,true,true),   // (4,0)
        Cell(false,true,false,true),   // (4,1)
        Cell(true,false,true,false),   // (4,2)
        Cell(false,true,false,true),   // (4,3)
        Cell(true,false,false,false),  // (4,4)
        Cell(false,true,true,false),   // (4,5)
        Cell(false,true,false,true),   // (4,6)
        Cell(true,false,false,false),  // (4,7)
        Cell(false,true,true,false),   // (4,8)
        Cell(false,true,false,true),   // (4,9)
        Cell(true,false,false,false),  // (4,10)
        Cell(false,true,true,false),   // (4,11)
        Cell(false,true,false,true),   // (4,12)
        Cell(true,false,false,false),  // (4,13)
        Cell(false,true,true,false)    // (4,14)
    },
    // Row 5 - Center of maze
    {
        Cell(false,true,false,true),   // (5,0)
        Cell(true,false,true,false),   // (5,1)
        Cell(false,true,false,true),   // (5,2)
        Cell(true,false,false,false),  // (5,3)
        Cell(false,true,true,false),   // (5,4)
        Cell(true,false,false,true),   // (5,5)
        Cell(true,false,false,false),  // (5,6)
        Cell(false,true,true,false),   // (5,7)
        Cell(true,false,false,true),   // (5,8)
        Cell(true,false,false,false),  // (5,9)
        Cell(false,true,true,false),   // (5,10)
        Cell(true,false,false,true),   // (5,11)
        Cell(true,false,false,false),  // (5,12)
        Cell(false,true,true,false),   // (5,13)
        Cell(true,false,true,false)    // (5,14)
    },
    // Row 6 - Symmetrical complexity
    {
        Cell(false,false,true,true),   // (6,0)
        Cell(false,true,false,true),   // (6,1)
        Cell(true,false,true,false),   // (6,2)
        Cell(false,true,false,true),   // (6,3)
        Cell(true,false,false,false),  // (6,4)
        Cell(false,true,true,false),   // (6,5)
        Cell(false,true,false,true),   // (6,6)
        Cell(true,false,false,false),  // (6,7)
        Cell(false,true,true,false),   // (6,8)
        Cell(false,true,false,true),   // (6,9)
        Cell(true,false,false,false),  // (6,10)
        Cell(false,true,true,false),   // (6,11)
        Cell(false,true,false,true),   // (6,12)
        Cell(true,false,false,false),  // (6,13)
        Cell(false,true,true,false)    // (6,14)
    },
    // Row 7 - Path continues
    {
        Cell(false,true,false,true),   // (7,0)
        Cell(true,false,true,false),   // (7,1)
        Cell(false,true,false,true),   // (7,2)
        Cell(true,false,false,false),  // (7,3)
        Cell(false,true,true,false),   // (7,4)
        Cell(true,false,false,true),   // (7,5)
        Cell(true,false,false,false),  // (7,6)
        Cell(false,true,true,false),   // (7,7)
        Cell(true,false,false,true),   // (7,8)
        Cell(true,false,false,false),  // (7,9)
        Cell(false,true,true,false),   // (7,10)
        Cell(true,false,false,true),   // (7,11)
        Cell(true,false,false,false),  // (7,12)
        Cell(false,true,true,false),   // (7,13)
        Cell(true,false,true,false)    // (7,14)
    },
    // Row 8 - Approaching goal
    {
        Cell(false,false,true,true),   // (8,0)
        Cell(false,true,false,true),   // (8,1)
        Cell(true,false,true,false),   // (8,2)
        Cell(false,true,false,true),   // (8,3)
        Cell(true,false,false,false),  // (8,4)
        Cell(false,true,true,false),   // (8,5)
        Cell(false,true,false,true),   // (8,6)
        Cell(true,false,false,false),  // (8,7)
        Cell(false,true,true,false),   // (8,8)
        Cell(false,true,false,true),   // (8,9)
        Cell(true,false,false,false),  // (8,10)
        Cell(false,true,true,false),   // (8,11)
        Cell(false,true,false,true),   // (8,12)
        Cell(true,false,false,false),  // (8,13)
        Cell(false,true,true,false)    // (8,14)
    },
    // Row 9 - Multiple paths converge
    {
        Cell(false,true,false,true),   // (9,0)
        Cell(true,false,true,false),   // (9,1)
        Cell(false,true,false,true),   // (9,2)
        Cell(true,false,false,false),  // (9,3)
        Cell(false,true,true,false),   // (9,4)
        Cell(true,false,false,true),   // (9,5)
        Cell(true,false,false,false),  // (9,6)
        Cell(false,true,true,false),   // (9,7)
        Cell(true,false,false,true),   // (9,8)
        Cell(true,false,false,false),  // (9,9)
        Cell(false,true,true,false),   // (9,10)
        Cell(true,false,false,true),   // (9,11)
        Cell(true,false,false,false),  // (9,12)
        Cell(false,true,true,false),   // (9,13)
        Cell(true,false,true,false)    // (9,14)
    },
    // Row 10 - Final approach
    {
        Cell(false,false,true,true),   // (10,0)
        Cell(false,true,false,true),   // (10,1)
        Cell(true,false,true,false),   // (10,2)
        Cell(false,true,false,true),   // (10,3)
        Cell(true,false,false,false),  // (10,4)
        Cell(false,true,true,false),   // (10,5)
        Cell(false,true,false,true),   // (10,6)
        Cell(true,false,false,false),  // (10,7)
        Cell(false,true,true,false),   // (10,8)
        Cell(false,true,false,true),   // (10,9)
        Cell(true,false,false,false),  // (10,10)
        Cell(false,true,true,false),   // (10,11)
        Cell(false,true,false,true),   // (10,12)
        Cell(true,false,false,false),  // (10,13)
        Cell(false,true,true,false)    // (10,14)
    },
    // Row 11 - Path to goal area
    {
        Cell(false,true,false,true),   // (11,0)
        Cell(true,false,true,false),   // (11,1)
        Cell(false,true,false,true),   // (11,2)
        Cell(true,false,false,false),  // (11,3)
        Cell(false,true,true,false),   // (11,4)
        Cell(true,false,false,true),   // (11,5)
        Cell(true,false,false,false),  // (11,6)
        Cell(false,true,true,false),   // (11,7)
        Cell(true,false,false,true),   // (11,8)
        Cell(true,false,false,false),  // (11,9)
        Cell(false,true,true,false),   // (11,10)
        Cell(true,false,false,true),   // (11,11)
        Cell(true,false,false,false),  // (11,12)
        Cell(false,true,true,false),   // (11,13)
        Cell(true,false,true,false)    // (11,14)
    },
    // Row 12 - Almost there
    {
        Cell(false,false,true,true),   // (12,0)
        Cell(false,true,false,true),   // (12,1)
        Cell(true,false,true,false),   // (12,2)
        Cell(false,true,false,true),   // (12,3)
        Cell(true,false,false,false),  // (12,4)
        Cell(false,true,true,false),   // (12,5)
        Cell(false,true,false,true),   // (12,6)
        Cell(true,false,false,false),  // (12,7)
        Cell(false,true,true,false),   // (12,8)
        Cell(false,true,false,true),   // (12,9)
        Cell(true,false,false,false),  // (12,10)
        Cell(false,true,true,false),   // (12,11)
        Cell(false,true,false,true),   // (12,12)
        Cell(true,false,false,false),  // (12,13)
        Cell(false,true,true,false)    // (12,14)
    },
    // Row 13 - Final row before goal
    {
        Cell(false,true,false,true),   // (13,0)
        Cell(true,false,true,false),   // (13,1)
        Cell(false,true,false,true),   // (13,2)
        Cell(true,false,false,false),  // (13,3)
        Cell(false,true,true,false),   // (13,4)
        Cell(true,false,false,true),   // (13,5)
        Cell(true,false,false,false),  // (13,6)
        Cell(false,true,true,false),   // (13,7)
        Cell(true,false,false,true),   // (13,8)
        Cell(true,false,false,false),  // (13,9)
        Cell(false,true,true,false),   // (13,10)
        Cell(true,false,false,true),   // (13,11)
        Cell(true,false,false,false),  // (13,12)
        Cell(false,false,false,false), // (13,13) - Open path to goal!
        Cell(true,false,true,false)    // (13,14)
    },
    // Row 14 - Goal row
    {
        Cell(false,true,false,true),   // (14,0)
        Cell(false,true,false,false),  // (14,1)
        Cell(false,true,false,false),  // (14,2)
        Cell(false,true,false,false),  // (14,3)
        Cell(false,true,false,false),  // (14,4)
        Cell(false,true,false,false),  // (14,5)
        Cell(false,true,false,false),  // (14,6)
        Cell(false,true,false,false),  // (14,7)
        Cell(false,true,false,false),  // (14,8)
        Cell(false,true,false,false),  // (14,9)
        Cell(false,true,false,false),  // (14,10)
        Cell(false,true,false,false),  // (14,11)
        Cell(false,true,false,false),  // (14,12)
        Cell(false,true,false,false),  // (14,13) - Path to goal
        Cell(true,true,true,false)     // (14,14) Goal
    }
};