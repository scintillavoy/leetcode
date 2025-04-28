#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < mat.size(); ++i) {
      pq.push(
          {mat[i].rend() - lower_bound(mat[i].rbegin(), mat[i].rend(), 1), i});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<int> result;
    while (!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
