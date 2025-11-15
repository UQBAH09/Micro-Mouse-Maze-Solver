#include <vector>
#include <queue>
#include "cell.h"
using namespace std;

struct corr {
    int row, col;
    corr(int r = -1, int c = -1) : row(r), col(c) {}
};

bool inBounds(corr c, int ROW, int COL) {
    return c.row >= 0 && c.row < ROW && c.col >= 0 && c.col < COL;
}

bool isEqual(corr a, corr b) {
    return a.row == b.row && a.col == b.col;
}

bool BFS(corr start, corr goal, vector<vector<Cell>>& maze, int ROW, int COL) {

    // parent for path reconstruction
    vector<vector<corr>> parent(ROW, vector<corr>(COL, corr(-1,-1)));
    queue<corr> q;

    maze[start.row][start.col].setExplored();  // mark start as visited/explored
    q.push(start);

    while (!q.empty()) {
        corr cur = q.front();
        q.pop();

        // Goal reached → reconstruct path
        if (isEqual(cur, goal)) {
            corr p = goal;
            while (!isEqual(p, start)) {
                maze[p.row][p.col].setpath();   // mark final path
                p = parent[p.row][p.col];
            }
            maze[start.row][start.col].setpath();
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

            // check wall + bounds
            if (!maze[cur.row][cur.col].isWall(i) && inBounds(nxt, ROW, COL)) {

                // only visit if not already explored
                if (!maze[nxt.row][nxt.col].isExplored()) {
                    maze[nxt.row][nxt.col].setExplored();  // mark explored/visited
                    parent[nxt.row][nxt.col] = cur;
                    q.push(nxt);
                }
            }
        }
    }
    return false; // no path
}
