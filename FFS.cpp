#include <vector>
#include <queue>
#include "cell.h"
#include "helper.h"

using namespace std;

void floodFromGoal(corr goal, vector<vector<Cell>>& maze, int ROW, int COL) {
    queue<corr> q;

    // Goal has distance 0
    maze[goal.row][goal.col].setDistance(0);
    maze[goal.row][goal.col].setExplored();
    q.push(goal);

    while (!q.empty()) {
        corr cur = q.front(); q.pop();
        int r = cur.row;
        int c = cur.col;

        int curDist = maze[r][c].getDisatance();

        corr neigh[4] = {
            corr(r - 1, c),      // north (0)
            corr(r + 1, c),      // south (1)
            corr(r, c + 1),  // east  (2)
            corr(r, c - 1)   // west  (3)
        };

        for (int i = 0; i < 4; i++) {
            corr nxt = neigh[i];

            if (!inBounds(nxt, ROW, COL)) continue;
            if (maze[r][c].isWall(i))    continue;  // wall in that direction

            // Only visit uninitialized cells
            if (maze[nxt.row][nxt.col].getDisatance() != -1) continue;

            maze[nxt.row][nxt.col].setDistance(curDist + 1);
            maze[nxt.row][nxt.col].setExplored();
            q.push(nxt);
        }
    }
}

bool FFS(corr start, corr goal, vector<vector<Cell>>& maze, int ROW, int COL) {
    floodFromGoal(goal, maze, ROW, COL);

    // If start is unreachable from the goal, no path
    if (maze[start.row][start.col].getDisatance() == -1) {
        return false;
    }

    corr cur = start;

    while (!isEqual(cur, goal)) {
        maze[cur.row][cur.col].setpath();   // mark current cell in final path
        int r = cur.row;
        int c = cur.col;
        int curDist = maze[r][c].getDisatance();

        corr neigh[4] = {
            corr(r - 1, c),      // north
            corr(r + 1, c),      // south
            corr(r,     c + 1),  // east
            corr(r,     c - 1)   // west
        };

        bool moved = false;
        corr best = cur;
        int bestDist = curDist;

        // Choose neighbor with smallest distance (must be < curDist)
        for (int i = 0; i < 4; i++) {
            corr nxt = neigh[i];

            if (!inBounds(nxt, ROW, COL)) continue;
            if (maze[r][c].isWall(i))       continue;

            int d = maze[nxt.row][nxt.col].getDisatance();
            if (d != -1 && d < bestDist) {
                bestDist = d;
                best = nxt;
                moved = true;
            }
        }

        if (!moved) {
            // No neighbor closer to goal -> no valid downhill path
            return false;
        }

        cur = best;
    }

    // Mark goal as part of the path too
    maze[goal.row][goal.col].setpath();
    return true;
}
