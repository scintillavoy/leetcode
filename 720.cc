#include <string>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  void insert(const string &word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); ++i) {
      int index = word[i] - 'a';
      if (curr->children[index] == nullptr) {
        curr->children[index] = new TrieNode();
      }
      curr = curr->children[index];
    }
    curr->exist = true;
  }

  bool search(const string &word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); ++i) {
      int index = word[i] - 'a';
      curr = curr->children[index];
      if (curr == nullptr || !curr->exist) {
        return false;
      }
    }
    return true;
  }

 private:
  struct TrieNode {
    bool exist = false;
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
  };

  TrieNode *root;

  void delete_trie(TrieNode *node) {
    if (node == nullptr) {
      return;
    }
    for (int i = 0; i < node->children.size(); ++i) {
      delete_trie(node->children[i]);
    }
    delete node;
  }
};

class Solution {
 public:
  string longestWord(vector<string> &words) {
    Trie trie;
    for (const auto &word : words) {
      trie.insert(word);
    }
    string longest_word;
    for (const auto &word : words) {
      if (word.size() < longest_word.size()) {
        continue;
      }
      if (trie.search(word) &&
          (word.size() > longest_word.size() || word < longest_word)) {
        longest_word = word;
      }
    }
    return longest_word;
  }
};
