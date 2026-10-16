
class Trie {
private:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->children[idx] == nullptr) {
                node->children[idx] = new Node();
            }

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->children[idx] == nullptr) {
                return false;
            }

            node = node->children[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (node->children[idx] == nullptr) {
                return false;
            }

            node = node->children[idx];
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