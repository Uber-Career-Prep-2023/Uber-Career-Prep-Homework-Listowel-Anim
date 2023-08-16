#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// Time Spent : 15 minutes
// Technique : Dynamic Programming
bool canBeSegmented(string s, unordered_set<string>& dictionary) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (dp[j] && dictionary.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    unordered_set<string> dictionary = {"Elf", "Go", "Golf", "Man", "Manatee", "Not", "Note", "Pig", "Quip", "Tee", "Teen"};

    cout << (canBeSegmented("mangolf", dictionary) ? "True" : "False") << endl;
    cout << (canBeSegmented("manateenotelf", dictionary) ? "True" : "False") << endl;
    cout << (canBeSegmented("quipig", dictionary) ? "True" : "False") << endl;

    return 0;
}
