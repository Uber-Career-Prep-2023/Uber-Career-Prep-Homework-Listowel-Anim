#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    bool validWord;

    TrieNode() : children(26, nullptr), validWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->validWord = true;
    }

    bool isValidWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->validWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (!curr->children[c - 'a']) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }

    void remove(string word) {
        removeRecursive(root, word, 0);
    }

private:
    bool removeRecursive(TrieNode* node, const string& word, int depth) {
        if (depth == word.length()) {
            if (!node->validWord) {
                return false; // Word not found
            }
            node->validWord = false;
            return node->children.empty(); // Return whether this node has no children
        }

        char c = word[depth];
        if (!node->children[c - 'a']) {
            return false; // Word not found
        }

        bool shouldRemoveChild = removeRecursive(node->children[c - 'a'], word, depth + 1);

        if (shouldRemoveChild) {
            delete node->children[c - 'a'];
            node->children[c - 'a'] = nullptr;
            return node->validWord || node->children.empty();
        }

        return false;
    }
};

#include <iostream>

void runTests() {
    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("bat");
    trie.insert("ball");

    // Search tests
    cout << "Search Tests:" << endl;
    cout << trie.isValidWord("apple") << endl;  // Should output 1 (true)
    cout << trie.isValidWord("app") << endl;    // Should output 1 (true)
    cout << trie.isValidWord("banana") << endl; // Should output 1 (true)
    cout << trie.isValidWord("batman") << endl; // Should output 0 (false)
    cout << trie.isValidWord("ball") << endl;   // Should output 1 (true)
    cout << trie.isValidWord("bat") << endl;    // Should output 1 (true)
    cout << trie.isValidWord("appe") << endl;   // Should output 0 (false)
    cout << endl;

    // Prefix search tests
    cout << "Prefix Search Tests:" << endl;
    cout << trie.startsWith("ap") << endl;   // Should output 1 (true)
    cout << trie.startsWith("ban") << endl;  // Should output 1 (true)
    cout << trie.startsWith("ba") << endl;   // Should output 1 (true)
    cout << trie.startsWith("ball") << endl; // Should output 1 (true)
    cout << trie.startsWith("bat") << endl;  // Should output 1 (true)
    cout << trie.startsWith("bae") << endl;  // Should output 0 (false)
    cout << endl;

    // Remove tests
    cout << "Remove Tests:" << endl;
    trie.remove("app");
    cout << trie.isValidWord("app") << endl;    // Should output 0 (false)
    cout << trie.startsWith("ap") << endl;      // Should output 1 (true)
    trie.remove("banana");
    cout << trie.isValidWord("banana") << endl; // Should output 0 (false)
    cout << trie.startsWith("ban") << endl;     // Should output 0 (false)
}

int main() {
    runTests();
    return 0;
}
