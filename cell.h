#ifndef CELL_H
#define CELL_H

class Cell {
    bool wall[4];
    bool path;
    bool explored;
public:
    Cell(bool north = false, bool south = false, bool east = false, bool west = false): path(false), explored(false) 
    {
        wall[0] = north;
        wall[1] = south;
        wall[2] = east;
        wall[3] = west;
    }

    bool isWall(int d) const {
        if (d < 0 || d > 3) return false;
        return wall[d];
    }

    void setpath() { path = true; }
    void clearpath() { path = false; }
    bool isPath() const { return path; }

    void setExplored() { explored = true; }
    bool isExplored() const { return explored; }

    void clear(){
        path = false;
        explored = false;
    }
};

#endif