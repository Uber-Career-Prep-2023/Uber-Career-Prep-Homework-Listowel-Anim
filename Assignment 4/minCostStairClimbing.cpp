#include <iostream>
#include <vector>
using namespace std;
// Time Spent: 12 minutes
// Technique : Dynamic Programming

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n, 0);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; ++i) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

int main() {
    vector<int> cost1 = {4, 1, 6, 3, 5, 8};
    cout << "Minimum cost: " << minCostClimbingStairs(cost1) << endl;

    vector<int> cost2 = {11, 8, 3, 4, 9, 13, 10};
    cout << "Minimum cost: " << minCostClimbingStairs(cost2) << endl;

    return 0;
}
