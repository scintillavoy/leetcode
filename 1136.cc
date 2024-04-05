#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1);
    for (const auto& relation : relations) {
      int from = relation[0];
      int to = relation[1];
      graph[from].push_back(to);
      ++in_degree[to];
    }
    queue<int> q, q2;
    for (int i = 1; i <= n; ++i) {
      if (in_degree[i] == 0) {
        q.push(i);
      }
    }
    int count = 1;
    vector<int> finished;
    while (!q.empty() || !q2.empty()) {
      if (q.empty()) {
        q = q2;
        q2 = queue<int>();
        ++count;
      }
      int curr = q.front();
      q.pop();
      for (const auto& adj : graph[curr]) {
        --in_degree[adj];
        if (in_degree[adj] == 0) {
          q2.push(adj);
        }
      }
      finished.push_back(curr);
    }
    if (finished.size() == n) {
      return count;
    } else {
      return -1;
    }
  }
};
