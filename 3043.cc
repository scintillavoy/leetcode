#include <algorithm>
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
      int index = c - '0';
      if (curr->children[index] == nullptr) {
        curr->children[index] = new TrieNode();
      }
      curr = curr->children[index];
    }
    curr->is_end = true;
  }

  int find_longest_prefix_length(const string& word) {
    int max_length = 0;
    TrieNode* curr = root;
    for (const auto c : word) {
      int index = c - '0';
      if (curr->children[index] == nullptr) {
        break;
      }
      curr = curr->children[index];
      ++max_length;
    }
    return max_length;
  }

 private:
  struct TrieNode {
    bool is_end = false;
    vector<TrieNode*> children = vector<TrieNode*>(10);
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
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    Trie trie;
    for (const auto num : arr1) {
      trie.insert(to_string(num));
    }
    int max_length = 0;
    for (const auto num : arr2) {
      string num_str = to_string(num);
      if (num_str.size() <= max_length) {
        continue;
      }
      max_length = max(max_length, trie.find_longest_prefix_length(num_str));
    }
    return max_length;
  }
};
