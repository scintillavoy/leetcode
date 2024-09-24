#include <string>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  void insert(const string& word) {
    TrieNode* curr = root;
    for (const auto c : word) {
      int index = c - 'a';
      if (curr->children[index] == nullptr) {
        curr->children[index] = new TrieNode();
      }
      curr = curr->children[index];
      ++curr->count;
    }
    curr->is_end = true;
  }

  int count_by_prefix(const string& prefix) {
    TrieNode* curr = root;
    for (const auto c : prefix) {
      int index = c - 'a';
      if (curr->children[index] == nullptr) {
        return 0;
      }
      curr = curr->children[index];
    }
    return curr->count;
  }

 private:
  struct TrieNode {
    int count = 0;
    bool is_end = false;
    vector<TrieNode*> children = vector<TrieNode*>(26);
  };

  TrieNode* root;

  void delete_trie(TrieNode* node) {
    if (node == nullptr) {
      return;
    }
    for (auto it = node->children.begin(); it != node->children.end(); ++it) {
      delete_trie(*it);
    }
    delete node;
  }
};

class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    Trie trie;
    for (const auto& word : words) {
      trie.insert(word);
    }
    return trie.count_by_prefix(pref);
  }
};
