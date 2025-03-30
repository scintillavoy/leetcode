#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new TrieNode(); };
  ~Trie() { delete_trie(root); };

  void insert(const string& word) {
    TrieNode* curr = root;
    for (const auto c : word) {
      if (!curr->children.contains(c)) {
        curr->children[c] = new TrieNode();
      }
      curr = curr->children[c];
    }
    curr->is_end = true;
  }

  bool search(const string& word) {
    TrieNode* curr = root;
    for (const auto c : word) {
      if (!curr->children.contains(c)) {
        return false;
      }
      curr = curr->children[c];
    }
    return curr->is_end;
  }

 private:
  struct TrieNode {
    bool is_end = false;
    unordered_map<char, TrieNode*> children;
  };

  TrieNode* root;

  void delete_trie(TrieNode* node) {
    if (node == nullptr) {
      return;
    }
    for (const auto [_, child] : node->children) {
      delete_trie(child);
    }
    delete node;
  }
};

class Solution {
 public:
  bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
    Trie trie;
    for (const auto& banned_word : bannedWords) {
      trie.insert(banned_word);
    }
    int count = 0;
    for (const auto& word : message) {
      if (trie.search(word)) {
        ++count;
        if (count == 2) {
          return true;
        }
      }
    }
    return false;
  }
};
