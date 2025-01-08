#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  int insert(const string &word) {
    TrieNode *curr = root;
    int total_count = 0;
    for (int i = 0; i < word.size(); ++i) {
      int key = (word[i] - 'a') * 26 + word[word.size() - 1 - i] - 'a';
      if (!curr->children.contains(key)) {
        curr->children[key] = new TrieNode();
      }
      curr = curr->children[key];
      total_count += curr->count;
    }
    curr->count += 1;
    return total_count;
  }

 private:
  struct TrieNode {
    int count = 0;
    unordered_map<int, TrieNode *> children;
  };

  TrieNode *root;

  void delete_trie(TrieNode *node) {
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
  int countPrefixSuffixPairs(vector<string> &words) {
    Trie trie;
    int result = 0;
    for (const auto &word : words) {
      result += trie.insert(word);
    }
    return result;
  }
};
