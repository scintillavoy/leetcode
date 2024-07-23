#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products,
                                           string searchWord) {
    for (const auto& product : products) {
      insert(product);
    }
    vector<vector<string>> result(searchWord.size());
    Node* curr = root;
    string prefix;
    for (int i = 0; i < searchWord.size(); ++i) {
      curr = curr->children[searchWord[i] - 'a'];
      prefix += searchWord[i];
      vector<string> suggestions;
      suggest(curr, prefix, suggestions);
      if (suggestions.size() == 0) {
        break;
      }
      result[i] = suggestions;
    }
    return result;
  }

 private:
  struct Node {
    bool exist;
    vector<Node*> children;
    Node() : exist(false), children(vector<Node*>(26, nullptr)) {}
  };

  Node* root = new Node();

  void insert(const string& str) {
    Node* curr = root;
    for (const auto c : str) {
      if (curr->children[c - 'a'] == nullptr) {
        curr->children[c - 'a'] = new Node();
      }
      curr = curr->children[c - 'a'];
    }
    curr->exist = true;
  }

  void suggest(Node* node, string& prefix, vector<string>& suggestions) {
    if (node == nullptr) {
      return;
    }
    if (node->exist) {
      suggestions.push_back(prefix);
      if (suggestions.size() == 3) {
        return;
      }
    }
    for (int i = 0; i < node->children.size(); ++i) {
      prefix.push_back(i + 'a');
      suggest(node->children[i], prefix, suggestions);
      prefix.pop_back();
      if (suggestions.size() == 3) {
        return;
      }
    }
  }
};
