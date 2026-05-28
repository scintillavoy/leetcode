#include <limits>
#include <string>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete_trie(root); }

  void insert(const string& word, int word_index) {
    TrieNode* curr = root;
    if (curr->shortest_length > word.size()) {
      curr->shortest_length = word.size();
      curr->index_of_shortest = word_index;
    } else if (curr->shortest_length == word.size() &&
               curr->index_of_shortest > word_index) {
      curr->index_of_shortest = word_index;
    }
    for (auto it = word.rbegin(); it != word.rend(); ++it) {
      if (curr->children[*it - 'a'] == nullptr) {
        curr->children[*it - 'a'] = new TrieNode();
      }
      curr = curr->children[*it - 'a'];
      if (curr->shortest_length > word.size()) {
        curr->shortest_length = word.size();
        curr->index_of_shortest = word_index;
      } else if (curr->shortest_length == word.size() &&
                 curr->index_of_shortest > word_index) {
        curr->index_of_shortest = word_index;
      }
    }
  }

  int search(const string& word) {
    TrieNode* curr = root;
    for (auto it = word.rbegin(); it != word.rend(); ++it) {
      if (curr->children[*it - 'a'] == nullptr) {
        return curr->index_of_shortest;
      }
      curr = curr->children[*it - 'a'];
    }
    return curr->index_of_shortest;
  }

 private:
  struct TrieNode {
    int shortest_length = numeric_limits<int>::max();
    int index_of_shortest = 0;
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
  };

  TrieNode* root;

  void delete_trie(TrieNode* node) {
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
  vector<int> stringIndices(vector<string>& wordsContainer,
                            vector<string>& wordsQuery) {
    Trie trie;
    for (int i = 0; i < wordsContainer.size(); ++i) {
      trie.insert(wordsContainer[i], i);
    }
    vector<int> result;
    for (const auto& word : wordsQuery) {
      result.push_back(trie.search(word));
    }
    return result;
  }
};
