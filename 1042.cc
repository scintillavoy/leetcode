#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<vector<int>> graph(n);
    for (const auto& path : paths) {
      graph[path[0] - 1].push_back(path[1] - 1);
      graph[path[1] - 1].push_back(path[0] - 1);
    }
    vector<int> answer(n);
    for (int i = 0; i < n; ++i) {
      vector<bool> used_types(4);
      for (const auto& adj : graph[i]) {
        if (answer[adj] == 0) {
          continue;
        }
        used_types[answer[adj] - 1] = true;
      }
      for (int j = 0; j < used_types.size(); ++j) {
        if (!used_types[j]) {
          answer[i] = j + 1;
          break;
        }
      }
    }
    return answer;
  }
};
