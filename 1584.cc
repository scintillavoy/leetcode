#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    vector<Edge> edges;
    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        edges.push_back({get_distance(points[i], points[j]), i, j});
      }
    }
    sort(edges.begin(), edges.end());
    parents = vector<int>(points.size());
    for (int i = 0; i < points.size(); ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(points.size());
    int min_cost = 0;
    int num_of_unions = 0;
    for (int i = 0; i < edges.size(); ++i) {
      if (union_set(edges[i].from, edges[i].to)) {
        min_cost += edges[i].weight;
        ++num_of_unions;
        if (num_of_unions == points.size() - 1) {
          break;
        }
      }
    }
    return min_cost;
  }

 private:
  struct Edge {
    int weight;
    int from;
    int to;

    bool operator<(const Edge &other) const { return weight < other.weight; }
  };

  vector<int> parents;
  vector<int> ranks;

  int get_distance(vector<int> &a, vector<int> &b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }

  int find_set(int x) {
    if (parents[x] != x) {
      parents[x] = find_set(parents[x]);
    }
    return parents[x];
  }

  bool union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return false;
    }
    if (ranks[x] > ranks[y]) {
      swap(x, y);
    } else if (ranks[x] == ranks[y]) {
      ++ranks[y];
    }
    parents[x] = y;
    return true;
  }
};
