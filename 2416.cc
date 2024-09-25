#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  void insert(const string& word) {
    TrieNode* curr = root;
    for (const auto c : word) {
      if (curr->children[c] == nullptr) {
        curr->children[c] = new TrieNode();
      }
      curr = curr->children[c];
      ++curr->count;
    }
  }

  int search(const string& word) {
    int total_count = 0;
    TrieNode* curr = root;
    for (const auto c : word) {
      if (curr->children[c] == nullptr) {
        break;
      }
      curr = curr->children[c];
      total_count += curr->count;
    }
    return total_count;
  }

 private:
  struct TrieNode {
    int count = 0;
    unordered_map<char, TrieNode*> children;
  };

  TrieNode* root;

  void delete_trie(TrieNode* node) {
    if (node == nullptr) {
      return;
    }
    for (auto it = node->children.begin(); it != node->children.end(); ++it) {
      delete_trie(it->second);
    }
    delete node;
  }
};

class Solution {
 public:
  vector<int> sumPrefixScores(vector<string>& words) {
    Trie trie;
    for (const auto& word : words) {
      trie.insert(word);
    }
    vector<int> scores;
    for (const auto& word : words) {
      scores.push_back(trie.search(word));
    }
    return scores;
  }
};
