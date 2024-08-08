#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> in_degree(numCourses);
    for (const auto& p : prerequisites) {
      graph[p[1]].push_back(p[0]);
      ++in_degree[p[0]];
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (in_degree[i] == 0) {
        q.push(i);
      }
    }
    vector<int> finished;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      finished.push_back(curr);
      for (const auto adj : graph[curr]) {
        --in_degree[adj];
        if (in_degree[adj] == 0) {
          q.push(adj);
        }
      }
    }
    if (finished.size() != numCourses) {
      return {};
    }
    return finished;
  }
};
