// 208. Implement Trie (Prefix Tree)
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
        root = new Node('\0'); // Root node with a null character as data
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (curr->children.count(ch)) {
                curr = curr->children[ch];
            } else {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
            }
        }
        curr->makeTerminal(); // Mark the end of the word
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) {
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->terminal;
    }

    // Check if any word in the Trie starts with the given prefix
    bool startsWith(const string& prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) {
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */