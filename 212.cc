#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    for (const auto& word : words) {
      insert(word);
    }
    m = board.size();
    n = board[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(i, j, root, board);
      }
    }
    return result;
  }

 private:
  struct Node {
    string word;
    vector<Node*> children;
    Node() : children(vector<Node*>(26)) {}
  };

  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  Node* root = new Node();
  int m;
  int n;
  vector<vector<bool>> visited;
  vector<string> result;

  void insert(const string& word) {
    Node* curr = root;
    for (const auto c : word) {
      if (curr->children[c - 'a'] == nullptr) {
        curr->children[c - 'a'] = new Node();
      }
      curr = curr->children[c - 'a'];
    }
    curr->word = word;
  }

  void dfs(int x, int y, Node* node, vector<vector<char>>& board) {
    node = node->children[board[x][y] - 'a'];
    if (node == nullptr) {
      return;
    }
    if (!node->word.empty()) {
      result.push_back(node->word);
      node->word.clear();
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
        continue;
      }
      dfs(x2, y2, node, board);
    }
    visited[x][y] = false;
  }
};
