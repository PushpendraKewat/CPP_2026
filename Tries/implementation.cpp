
#include<iostream>
#include<string>
#include<unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Node {
public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;

    Node(char data) {
        this->data = data;
        this->terminal = false;
    }

    void makeTerminal() {
        this->terminal = true;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('\0');
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        Node* curr = root;

        for(char ch : word) {
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
            } else {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
            }
        }

        curr->makeTerminal();
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        Node* curr = root;

        for(char ch : word) {
            if(!curr->children.count(ch)) {
                return false;
            }

            curr = curr->children[ch];
        }

        return curr->terminal;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const string& prefix) {
        Node* curr = root;

        for(char ch : prefix) {
            if(!curr->children.count(ch)) {
                return false;
            }

            curr = curr->children[ch];
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << std::boolalpha;

    cout << "Search apple: " << trie.search("apple") << endl;
    cout << "Search app: " << trie.search("app") << endl;
    cout << "Search ap: " << trie.search("ap") << endl;

    cout << "Prefix ap: " << trie.startsWith("ap") << endl;
    cout << "Prefix ba: " << trie.startsWith("ba") << endl;
    cout << "Prefix ca: " << trie.startsWith("ca") << endl;

    return 0;
}
