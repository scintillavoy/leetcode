#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  void insert(const string& word) {
    TrieNode* node = root;
    for (const auto c : word) {
      if (!node->children.contains(c)) {
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
    }
    ++node->end_count;
  }

  bool has_prefix(const string& prefix) {
    TrieNode* node = root;
    for (const auto c : prefix) {
      if (!node->children.contains(c)) {
        return false;
      }
      node = node->children[c];
    }
    return node->end_count > 1 || !node->children.empty();
  }

 private:
  struct TrieNode {
    int end_count = 0;
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
  bool phonePrefix(vector<string>& numbers) {
    Trie trie;
    for (const auto& number : numbers) {
      trie.insert(number);
    }
    for (const auto& number : numbers) {
      if (trie.has_prefix(number)) {
        return false;
      }
    }
    return true;
  }
};
