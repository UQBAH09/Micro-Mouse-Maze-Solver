#include <vector>
#include "cell.h"
#include "helper.h"

using namespace std;

bool DFS(corr cur, corr goal, vector<vector<Cell>>& maze, int ROW, int COL) {
    if (!inBounds(cur, ROW, COL)) return false;
    if (maze[cur.row][cur.col].isExplored()) return false;

    maze[cur.row][cur.col].setExplored();// mark as visited/explored

    // base case: reached goal
    if (isEqual(cur, goal)) {
        maze[cur.row][cur.col].setpath();   // mark goal as part of path
        return true;
    }
    
    // Directions: N, S, E, W
    corr neigh[4] = {
        corr(cur.row - 1, cur.col),  // north
        corr(cur.row + 1, cur.col),  // south
        corr(cur.row,     cur.col + 1),  // east
        corr(cur.row,     cur.col - 1)   // west
    };

    for (int i = 0; i < 4; i++) {
        corr nxt = neigh[i];

        // check wall and bounds
        if (!maze[cur.row][cur.col].isWall(i) && inBounds(nxt, ROW, COL)) {
            if (!maze[nxt.row][nxt.col].isExplored()) {
                if (DFS(nxt, goal, maze, ROW, COL)) {
                    // If from this neighbor we can reach the goal
                    maze[cur.row][cur.col].setpath();
                    return true;
                }
            }
        }
    }
    return false;
}
