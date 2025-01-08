#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  bool is_end = false;
  vector<TrieNode *> children = vector<TrieNode *>(10);
};

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  TrieNode *root;

 private:
  void delete_trie(TrieNode *node) {
    if (node == nullptr) {
      return;
    }
    for (const auto child : node->children) {
      delete_trie(child);
    }
    delete node;
  }
};

class Solution {
 public:
  int equalDigitFrequency(string s) {
    Trie trie;
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
      TrieNode *node = trie.root;
      int num_of_unique_digits = 0;
      vector<int> frequencies(10);
      int max_frequency = 0;
      for (int j = i; j < s.size(); ++j) {
        int current_digit = s[j] - '0';
        if (node->children[current_digit] == nullptr) {
          node->children[current_digit] = new TrieNode();
        }
        node = node->children[current_digit];
        if (frequencies[current_digit] == 0) {
          ++num_of_unique_digits;
        }
        ++frequencies[current_digit];
        max_frequency = max(max_frequency, frequencies[current_digit]);
        if (!node->is_end &&
            num_of_unique_digits * max_frequency == j - i + 1) {
          node->is_end = true;
          ++result;
        }
      }
    }
    return result;
  }
};
