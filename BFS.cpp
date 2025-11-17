#include <vector>
#include <queue>
#include "cell.h"
#include "helper.h"

using namespace std;

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
            corr(cur.row - 1, cur.col),      // north  (0)
            corr(cur.row + 1, cur.col),      // south  (1)
            corr(cur.row,     cur.col + 1),  // east   (2)
            corr(cur.row,     cur.col - 1)   // west   (3)
        };

        for (int i = 0; i < 4; i++) {
            corr nxt = neigh[i];

            // 1) bounds check first
            if (!inBounds(nxt, ROW, COL)) continue;

            // 2) wall check from current cell in direction i
            if (maze[cur.row][cur.col].isWall(i)) continue;

            // 3) already visited?
            if (maze[nxt.row][nxt.col].isExplored()) continue;

            maze[nxt.row][nxt.col].setExplored();  // mark explored/visited
            parent[nxt.row][nxt.col] = cur;
            q.push(nxt);
        }
    }
    return false; // no path
}
