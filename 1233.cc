#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Trie {
 public:
  Trie() { root = new Node(); }
  ~Trie() { delete_trie(root); }

  void insert(const string& path) {
    Node* curr = root;
    istringstream iss(path);
    string folder;
    getline(iss, folder, '/');
    while (getline(iss, folder, '/')) {
      if (!curr->children.contains(folder)) {
        curr->children[folder] = new Node();
      }
      curr = curr->children[folder];
    }
    curr->is_end = true;
  }

  vector<string> find_non_subfolders() {
    vector<string> result;
    queue<pair<string, Node*>> q;
    q.push({"", root});
    while (!q.empty()) {
      auto [path, node] = q.front();
      q.pop();
      if (node->is_end) {
        result.push_back(path);
      } else {
        for (auto it = node->children.begin(); it != node->children.end();
             ++it) {
          q.push({
              path + "/" + it->first,
              it->second,
          });
        }
      }
    }
    return result;
  }

 private:
  struct Node {
    bool is_end = false;
    unordered_map<string, Node*> children;
  };

  Node* root;

  void delete_trie(Node* node) {
    if (root == nullptr) {
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
  vector<string> removeSubfolders(vector<string>& folder) {
    Trie trie;
    for (const auto& path : folder) {
      trie.insert(path);
    }
    return trie.find_non_subfolders();
  }
};
