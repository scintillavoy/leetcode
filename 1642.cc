#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < heights.size(); ++i) {
      if (heights[i - 1] >= heights[i]) {
        continue;
      }
      pq.push(heights[i] - heights[i - 1]);
      if (pq.size() > ladders) {
        if (bricks < pq.top()) {
          return i - 1;
        }
        bricks -= pq.top();
        pq.pop();
      }
    }
    return heights.size() - 1;
  }
};
