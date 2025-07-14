#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;


class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    // Recursive helper for search (to handle '.')
    bool searchHelper(string& word, TrieNode* node, int index) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchHelper(word, node->children[i], index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = ch - 'a';
            if (!node->children[idx]) return false;
            return searchHelper(word, node->children[idx], index + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, root, 0);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */