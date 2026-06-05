#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> in_degrees(n);
    for (const auto& edge : edges) {
      ++in_degrees[edge[1]];
    }
    vector<int> result;
    for (int i = 0; i < in_degrees.size(); ++i) {
      if (in_degrees[i] == 0) {
        result.push_back(i);
      }
    }
    return result;
  }
};
