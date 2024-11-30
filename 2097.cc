#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    unordered_map<int, vector<int>> adjacencies;
    unordered_map<int, int> in_degrees, out_degrees;
    for (const auto& pair : pairs) {
      adjacencies[pair[0]].push_back(pair[1]);
      ++out_degrees[pair[0]];
      ++in_degrees[pair[1]];
    }
    int start_node = pairs[0][0];
    for (const auto [node, out_degree] : out_degrees) {
      if (out_degree == in_degrees[node] + 1) {
        start_node = node;
        break;
      }
    }
    vector<int> sequence;
    dfs(start_node, adjacencies, sequence);
    vector<vector<int>> result;
    for (int i = sequence.size() - 1; i > 0; --i) {
      result.push_back({sequence[i], sequence[i - 1]});
    }
    return result;
  }

 private:
  void dfs(int curr, unordered_map<int, vector<int>>& adjacencies,
           vector<int>& sequence) {
    while (!adjacencies[curr].empty()) {
      int next = adjacencies[curr].back();
      adjacencies[curr].pop_back();
      dfs(next, adjacencies, sequence);
    }
    sequence.push_back(curr);
  }
};
