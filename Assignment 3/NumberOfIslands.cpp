#include <bits/stdc++.h>
//Time spent on problem : 32 mins
//Space Complexity: O(1)
//Time Complexity: O(m*n)

using namespace std;

void exploreIsland(vector<vector<int>>& grid, int row, int col) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] != 1) {
        return;
    }

    grid[row][col] = 0; // Mark the cell as visited

    // Explore the neighboring cells in all four directions
    exploreIsland(grid, row - 1, col); // Up
    exploreIsland(grid, row + 1, col); // Down
    exploreIsland(grid, row, col - 1); // Left
    exploreIsland(grid, row, col + 1); // Right
}

int countIslands(vector<vector<int>>& grid) {
    int numRows = grid.size();
    if (numRows == 0) {
        return 0;
    }

    int numCols = grid[0].size();
    int islandsCount = 0;

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (grid[row][col] == 1) {
                exploreIsland(grid, row, col);
                islandsCount++;
            }
        }
    }

    return islandsCount;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    int islands = countIslands(grid);
    cout << "Number of islands: " << islands << endl;

    return 0;
}

