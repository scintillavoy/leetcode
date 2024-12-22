#include <algorithm>
#include <deque>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> leftmostBuildingQueries(vector<int>& heights,
                                      vector<vector<int>>& queries) {
    vector<tuple<int, int, int>> query_index_tuples(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      int a = queries[i][0];
      int b = queries[i][1];
      if (a > b) {
        swap(a, b);
      }
      query_index_tuples[i] = {a, b, i};
    }
    sort(query_index_tuples.begin(), query_index_tuples.end(),
         [](const tuple<int, int, int> q1, const tuple<int, int, int> q2) {
           return get<1>(q1) > get<1>(q2);
         });
    vector<int> ans(query_index_tuples.size());
    deque<int> dq;
    for (auto [a, b, i] : query_index_tuples) {
      if (a == b) {
        ans[i] = a;
        continue;
      }
      if (heights[a] < heights[b]) {
        ans[i] = b;
        continue;
      }
      for (int index = (dq.empty() ? heights.size() - 1 : dq.front() - 1);
           index > b; --index) {
        while (!dq.empty() && heights[index] >= heights[dq.front()]) {
          dq.pop_front();
        }
        dq.push_front(index);
      }
      auto it =
          upper_bound(dq.begin(), dq.end(), a, [&](int value, int element) {
            return heights[a] < heights[element];
          });
      ans[i] = it == dq.end() ? -1 : *it;
    }
    return ans;
  }
};
