#include <bits/stdc++.h>
using namespace std;
//Tiime Spent: 18 mins
//Used a stack
//Time Complexity: O(n)
//Space Complexity: O(n)

string reverseWords(const std::string& str) {
    stack<std::string> wordStack;
    string word;
    string reversedStr;

    // Iterate over each character in the string
    for (char c : str) {
        if (c == ' ') {
            // Push the word onto the stack
            wordStack.push(word);
            word.clear();
        } else {
            // Build the word character by character
            word += c;
        }
    }

    // Push the last word onto the stack
    wordStack.push(word);

    // Pop words from the stack and append them to the reversed string
    while (!wordStack.empty()) {
        reversedStr += wordStack.top() + ' ';
        wordStack.pop();
    }

    // Remove the trailing space
    if (!reversedStr.empty()) {
        reversedStr.pop_back();
    }

    return reversedStr;
}

int main() {
    string input = "Hello World, how are you?";
    string reversed = reverseWords(input);
    cout << "Reversed string: " << reversed << std::endl;

    return 0;
}
