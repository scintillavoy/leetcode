#include <string>
#include <unordered_map>
using namespace std;

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  void insert(string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); ++i) {
      if (curr->children.count(word[i]) == 0) {
        curr->children[word[i]] = new TrieNode();
      }
      curr = curr->children[word[i]];
    }
    curr->exist = true;
  }

  bool search(string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); ++i) {
      if (curr->children.count(word[i]) == 0) {
        return false;
      }
      curr = curr->children[word[i]];
    }
    return curr->exist;
  }

  bool startsWith(string prefix) {
    TrieNode *curr = root;
    for (int i = 0; i < prefix.size(); ++i) {
      if (curr->children.count(prefix[i]) == 0) {
        return false;
      }
      curr = curr->children[prefix[i]];
    }
    return true;
  }

 private:
  struct TrieNode {
    bool exist = false;
    unordered_map<char, TrieNode *> children;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
