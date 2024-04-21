#include <functional>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCostToSupplyWater(int n, vector<int>& wells,
                           vector<vector<int>>& pipes) {
    parent = vector<int>(n + 1);
    for (int i = 0; i < n + 1; ++i) {
      parent[i] = i;
    }
    rank = vector<int>(n + 1);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    for (int i = 0; i < wells.size(); ++i) {
      pq.push({wells[i], i, n});
    }
    for (const auto& pipe : pipes) {
      pq.push({pipe[2], pipe[0] - 1, pipe[1] - 1});
    }
    int answer = 0;
    while (!pq.empty()) {
      auto [cost, x, y] = pq.top();
      pq.pop();
      if (find_set(x) == find_set(y)) {
        continue;
      }
      union_set(x, y);
      answer += cost;
    }
    return answer;
  }

 private:
  vector<int> parent;
  vector<int> rank;

  int find_set(int x) {
    if (parent[x] != x) {
      parent[x] = find_set(parent[x]);
    }
    return parent[x];
  }

  void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return;
    }
    if (rank[x] > rank[y]) {
      swap(x, y);
    } else if (rank[x] == rank[y]) {
      ++rank[y];
    }
    parent[x] = y;
  }
};
