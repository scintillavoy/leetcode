#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new Node(); }

  void insert(string word) {
    Node *curr = root;
    for (int i = 0; i < word.size(); ++i) {
      if (curr->children.count(word[i]) == 0) {
        curr->children[word[i]] = new Node();
      }
      curr = curr->children[word[i]];
    }
    curr->exist = true;
  }

  bool search(string word) {
    Node *curr = root;
    for (int i = 0; i < word.size(); ++i) {
      if (curr->children.count(word[i]) == 0) {
        return false;
      }
      curr = curr->children[word[i]];
    }
    return curr->exist;
  }

  bool startsWith(string prefix) {
    Node *curr = root;
    for (int i = 0; i < prefix.size(); ++i) {
      if (curr->children.count(prefix[i]) == 0) {
        return false;
      }
      curr = curr->children[prefix[i]];
    }
    return true;
  }

 private:
  struct Node {
    bool exist;
    unordered_map<char, Node *> children;
    Node() : exist(false), children({}) {}
  };

  Node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
