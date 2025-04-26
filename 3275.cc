#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> resultsArray(vector<vector<int>>& queries, int k) {
    priority_queue<int> pq;
    vector<int> result(queries.size(), -1);
    for (int i = 0; i < queries.size(); ++i) {
      pq.push(abs(queries[i][0]) + abs(queries[i][1]));
      if (pq.size() > k) {
        pq.pop();
      }
      if (pq.size() >= k) {
        result[i] = pq.top();
      }
    }
    return result;
  }
};
