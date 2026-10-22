
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
    int terminal;
    int prefixCount;
    unordered_map<char, Node*> children;

    Node(char data) {
        this->data = data;
        terminal = 0;
        prefixCount = 0;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('\0');
    }

    void insert(const string& word) {
        Node* curr = root;

        for(char ch : word) {
            if(!curr->children.count(ch)) {
                curr->children[ch] = new Node(ch);
            }

            curr = curr->children[ch];
            curr->prefixCount++;
        }

        curr->terminal++;
    }

    int countWordsEqualTo(const string& word) {
        Node* curr = root;

        for(char ch : word) {
            if(!curr->children.count(ch)) {
                return 0;
            }

            curr = curr->children[ch];
        }

        return curr->terminal;
    }

    int countWordsStartingWith(const string& prefix) {
        Node* curr = root;

        for(char ch : prefix) {
            if(!curr->children.count(ch)) {
                return 0;
            }

            curr = curr->children[ch];
        }

        return curr->prefixCount;
    }

    void erase(const string& word) {
        if(countWordsEqualTo(word) == 0) {
            return;
        }

        Node* curr = root;

        for(char ch : word) {
            curr = curr->children[ch];
            curr->prefixCount--;
        }

        curr->terminal--;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");

    cout << trie.countWordsEqualTo("apple") << endl;
    cout << trie.countWordsEqualTo("app") << endl;
    cout << trie.countWordsStartingWith("app") << endl;

    trie.erase("apple");

    cout << trie.countWordsEqualTo("apple") << endl;
    cout << trie.countWordsStartingWith("app") << endl;

    return 0;
}
