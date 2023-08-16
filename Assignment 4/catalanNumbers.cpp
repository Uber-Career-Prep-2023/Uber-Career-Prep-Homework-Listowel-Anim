#include <iostream>
#include <vector>
// Time Spent : 21 minutes
// Technique : Recursive Approach with memoization
using namespace std;

// Function to calculate the nth Catalan number
unsigned long long catalanNumber(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    unsigned long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += catalanNumber(i) * catalanNumber(n - 1 - i);
    }
    return res;
}

int main() {
    int n;
    cout << "Enter a non-negative integer n: ";
    cin >> n;

    cout << "Catalan numbers from 0 to " << n << ":\n";
    for (int i = 0; i <= n; ++i) {
        cout << catalanNumber(i) << " ";
    }

    return 0;
}
