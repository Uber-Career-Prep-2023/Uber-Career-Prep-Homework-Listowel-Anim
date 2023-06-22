#include <bits/stdc++.h>
using namespace std;

using namespace std;

unordered_map<int, unordered_set<int>> create_adjacency_list(const vector<pair<int, int>>& pairs) {
    unordered_map<int, unordered_set<int>> adjacency_list;

    for (const auto& pair : pairs) {
        int source = pair.first;
        int destination = pair.second;

        adjacency_list[source].insert(destination);

        // Check if the reverse edge exists
        if (adjacency_list[destination].find(source) == adjacency_list[destination].end()) {
            // If the reverse edge doesn't exist, add an undirected edge
            adjacency_list[destination].insert(source);
        }
    }

    return adjacency_list;
}

int main() {
    vector<pair<int, int>> pairs = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {2, 4}};

    unordered_map<int, unordered_set<int>> adjacency_list = create_adjacency_list(pairs);

    for (const auto& node : adjacency_list) {
        cout << "Node " << node.first << " is connected to: ";
        for (const auto& neighbor : node.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
