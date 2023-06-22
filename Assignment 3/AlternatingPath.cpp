#include <bits/stdc++.h>

using namespace std;
//Time Spent: 40 mins
//Time Complexity: O(n)
//Space Complexity: O(n)
//Used BFS algorithm

// Node class representing a vertex in the graph
class Node {
public:
    string name;
    unordered_map<Node*, string> neighbors;

    Node(string name) {
        this->name = name;
    }

    void addNeighbor(Node* neighbor, string color) {
        neighbors[neighbor] = color;
    }
};

int shortestPathLength(Node* origin, Node* destination) {
    // Initialize a queue for BFS traversal
    queue<pair<Node*, int>> q;

    // Initialize a set to keep track of visited nodes
    unordered_set<Node*> visited;

    // Push the origin node into the queue with path length 0
    q.push({origin, 0});
    visited.insert(origin);

    // Perform BFS traversal
    while (!q.empty()) {
        Node* currNode = q.front().first;
        int pathLength = q.front().second;
        q.pop();

        // Check if the current node is the destination
        if (currNode == destination)
            return pathLength;

        // Explore the neighbors of the current node
        for (auto neighbor : currNode->neighbors) {
            Node* nextNode = neighbor.first;
            string edgeColor = neighbor.second;

            // Check if the neighbor has a different edge color
            if (visited.find(nextNode) == visited.end() && edgeColor != currNode->neighbors[currNode]) {
                q.push({nextNode, pathLength + 1});
                visited.insert(nextNode);
            }
        }
    }

    // No path found
    return -1;
}

int main() {
    // Create nodes
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");

    // Add neighbors with edge colors
    A->addNeighbor(B, "blue");
    A->addNeighbor(C, "red");
    B->addNeighbor(D, "blue");
    B->addNeighbor(E, "blue");
    C->addNeighbor(B, "red");
    D->addNeighbor(C, "blue");
    A->addNeighbor(D, "red");
    D->addNeighbor(E, "red");
    E->addNeighbor(C, "red");

    // Define origin and destination
    Node* origin = A;
    Node* destination = E;

    // Find the shortest path length
    int shortestLength = shortestPathLength(origin, destination);

    // Print the result
    if (shortestLength != -1)
        cout << "Shortest path length: " << shortestLength << endl;
    else
        cout << "No path exists!" << endl;

    return 0;
}
