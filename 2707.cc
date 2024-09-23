#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  bool exist = false;
  vector<TrieNode*> children = vector<TrieNode*>(26);
};

class Trie {
 public:
  TrieNode* root;

  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  void insert(const string& word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.size(); ++i) {
      int index = word[i] - 'a';
      if (curr->children[index] == nullptr) {
        curr->children[index] = new TrieNode();
      }
      curr = curr->children[index];
    }
    curr->exist = true;
  }

 private:
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
  int minExtraChar(string s, vector<string>& dictionary) {
    Trie* trie = new Trie();
    for (const auto& word : dictionary) {
      trie->insert(word);
    }
    vector<int> min_extras(s.size() + 1);
    for (int start = s.size() - 1; start >= 0; --start) {
      min_extras[start] = min_extras[start + 1] + 1;
      TrieNode* node = trie->root;
      for (int end = start; end < s.size(); ++end) {
        int index = s[end] - 'a';
        if (node->children[index] == nullptr) {
          break;
        }
        node = node->children[index];
        if (node->exist) {
          min_extras[start] = min(min_extras[start], min_extras[end + 1]);
        }
      }
    }
    return min_extras.front();
  }
};
