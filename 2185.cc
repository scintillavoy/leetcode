#include <string>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new Node(); }

  void insert(const string& word) {
    Node* curr = root;
    for (const auto c : word) {
      if (curr->children[c - 'a'] == nullptr) {
        curr->children[c - 'a'] = new Node();
      }
      curr = curr->children[c - 'a'];
      ++curr->count;
    }
    curr->is_end = true;
  }

  int count_by_prefix(const string& prefix) {
    Node* curr = root;
    for (const auto c : prefix) {
      if (curr->children[c - 'a'] == nullptr) {
        return 0;
      }
      curr = curr->children[c - 'a'];
    }
    return curr->count;
  }

 private:
  struct Node {
    int count;
    bool is_end;
    vector<Node*> children;
    Node() : count(0), is_end(false), children(vector<Node*>(26, nullptr)) {}
  };

  Node* root;
};

class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    Trie* trie = new Trie();
    for (const auto& word : words) {
      trie->insert(word);
    }
    return trie->count_by_prefix(pref);
  }
};
