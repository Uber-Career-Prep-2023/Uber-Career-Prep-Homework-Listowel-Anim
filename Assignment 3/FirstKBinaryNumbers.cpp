#include <bits/stdc++.h>
using namespace std;

//Time Spent: 25 mins
//Space Complexity: O(n)
//Time Complexity: O(n)
//Used the BFS algorithm
vector<string> generateBinaryNumbers(int k) {
    vector<string> result;
    queue<string> q;
    q.push("1"); // Start with 1

    while (k > 0) {
        string num = q.front();
        q.pop();

        result.push_back(num);
        k--;

        // Append '0' and '1' to the current number to generate new binary numbers
        q.push(num + "0");
        q.push(num + "1");
    }

    return result;
}

int main() {
    int k = 5;
    vector<string> binaryNumbers = generateBinaryNumbers(k);

    cout << "First " << k << " binary numbers:" << endl;
    for (const string& num : binaryNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

