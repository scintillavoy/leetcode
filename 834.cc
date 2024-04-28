#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    graph = vector<vector<int>>(n);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    count = vector<int>(n, 1);
    answer = vector<int>(n);
    traverse(0, -1);
    traverse2(0, -1);
    return answer;
  }

 private:
  vector<vector<int>> graph;
  vector<int> count;
  vector<int> answer;

  void traverse(int curr, int parent) {
    for (const auto &adj : graph[curr]) {
      if (adj == parent) {
        continue;
      }
      traverse(adj, curr);
      count[curr] += count[adj];
      answer[curr] += answer[adj] + count[adj];
    }
  }

  void traverse2(int curr, int parent) {
    for (const auto &adj : graph[curr]) {
      if (adj == parent) {
        continue;
      }
      answer[adj] = answer[curr] - count[adj] + count.size() - count[adj];
      traverse2(adj, curr);
    }
  }
};
