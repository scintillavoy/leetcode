#include <string>
#include <unordered_map>
using namespace std;

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  void insert(string word) {
    TrieNode* curr = root;
    for (const auto c : word) {
      if (!curr->children.contains(c)) {
        curr->children[c] = new TrieNode();
      }
      curr = curr->children[c];
      ++curr->prefix_count;
    }
    ++curr->word_count;
  }

  int countWordsEqualTo(string word) {
    TrieNode* curr = root;
    for (const auto c : word) {
      if (!curr->children.contains(c)) {
        return 0;
      }
      curr = curr->children[c];
    }
    return curr->word_count;
  }

  int countWordsStartingWith(string prefix) {
    TrieNode* curr = root;
    for (const auto c : prefix) {
      if (!curr->children.contains(c)) {
        return 0;
      }
      curr = curr->children[c];
    }
    return curr->prefix_count;
  }

  void erase(string word) {
    TrieNode* curr = root;
    for (const auto c : word) {
      if (!curr->children.contains(c)) {
        return;
      }
      if (curr->children[c]->prefix_count == 1) {
        delete_trie(curr->children[c]);
        curr->children.erase(c);
        return;
      }
      curr = curr->children[c];
      --curr->prefix_count;
    }
    --curr->word_count;
  }

 private:
  struct TrieNode {
    int prefix_count = 0;
    int word_count = 0;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
