#include <iostream>
#include <vector>
using namespace std;
// Time Spent: 8 minutes
// Technique: Dynamic Programming
int coinChangeWays(vector<int>& coins, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1; // Base case: one way to make change for amount 0

    for (int coin : coins) {
        for (int i = coin; i <= target; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[target];
}

int main() {
    vector<int> coins = {2, 5, 10};
    int sum1 = 20;
    cout << "Number of ways to make change for " << sum1 << ": " << coinChangeWays(coins, sum1) << endl;

    int sum2 = 15;
    cout << "Number of ways to make change for " << sum2 << ": " << coinChangeWays(coins, sum2) << endl;

    return 0;
}
