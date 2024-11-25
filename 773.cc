#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                      {0, 4}, {1, 3, 5}, {2, 4}};
    string state;
    for (const auto& row : board) {
      for (const auto num : row) {
        state += to_string(num);
      }
    }
    unordered_set<string> visited;
    queue<string> q;
    visited.insert(state);
    q.push(state);
    int moves = 0;
    while (!q.empty()) {
      for (int i = q.size(); i > 0; --i) {
        state = q.front();
        q.pop();
        if (state == "123450") {
          return moves;
        }
        int zero_pos = state.find('0');
        for (const auto new_pos : directions[zero_pos]) {
          swap(state[zero_pos], state[new_pos]);
          if (!visited.contains(state)) {
            visited.insert(state);
            q.push(state);
          }
          swap(state[zero_pos], state[new_pos]);
        }
      }
      ++moves;
    }
    return -1;
  }
};
