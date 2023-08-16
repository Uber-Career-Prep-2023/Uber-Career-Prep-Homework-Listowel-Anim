#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Time Spent : 27 minutes
// Technique: Dynamic Programming
int largestSquareDimension(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0)
        return 0;

    int n = matrix[0].size();
    int maxSide = 0;
    
    // Create a 2D DP array to store the size of the largest square ending at each cell
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }

    return maxSide;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1}
    };

    int result = largestSquareDimension(matrix);
    cout << "Dimension of the largest square: " << result << endl;

    return 0;
}
