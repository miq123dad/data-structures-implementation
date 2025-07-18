#include <iostream>
using namespace std;

// Node structure for Trie
class TrieNode {
public:
    TrieNode* children[26]; 
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        // Initialize all children to nullptr
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    // Constructor
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a'; 
            if (!current->children[index])
                current->children[index] = new TrieNode();
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index])
                return false;
            current = current->children[index];
        }
        return current->isEndOfWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!current->children[index])
                return false;
            current = current->children[index];
        }
        return true;
    }

    // Destructor to free memory
    ~Trie() {
        clear(root);
    }

private:
    // Recursive function to delete Trie nodes
    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++)
            clear(node->children[i]);
        delete node;
    }
};

//  Test the Trie

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << boolalpha; // Print true/false instead of 1/0
    cout << "Search 'apple': " << trie.search("apple") << endl;
    cout << "Search 'app': " << trie.search("app") << endl;
    cout << "Search 'bat': " << trie.search("bat") << endl;
    cout << "Search 'bad': " << trie.search("bad") << endl;
    cout << "Prefix 'ap': " << trie.startsWith("ap") << endl;
    cout << "Prefix 'ba': " << trie.startsWith("ba") << endl;
    cout << "Prefix 'cat': " << trie.startsWith("cat") << endl;

    return 0;
}
