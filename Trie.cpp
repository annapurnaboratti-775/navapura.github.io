#include <iostream>
#include <unordered_map>
using namespace std;

struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class Trie {
    TrieNode* root;

    void suggestions(TrieNode* node, string prefix) {
        if (node->isEnd)
            cout << prefix << endl;

        for (auto &p : node->children)
            suggestions(p.second, prefix + p.first);
    }

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c])
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }

    void autocomplete(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->children[c]) {
                cout << "No courses found\n";
                return;
            }
            cur = cur->children[c];
        }
        suggestions(cur, prefix);
    }
};

int main() {
    Trie courses;
    courses.insert("digital_literacy");
    courses.insert("data_privacy");
    courses.insert("e_governance");
    courses.insert("cyber_security");

    cout << "Course suggestions for 'di':\n";
    courses.autocomplete("di");
    return 0;
}
