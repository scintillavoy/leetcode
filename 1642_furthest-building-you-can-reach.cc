#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int idx;
    for (idx = 0; idx < heights.size()-1; ++idx) {
      if (heights[idx] >= heights[idx+1]) {
        continue;
      }
      min_heap.push(heights[idx+1] - heights[idx]);
      if (min_heap.size() > ladders) {
        if (min_heap.top() <= bricks) {
          bricks -= min_heap.top();
          min_heap.pop();
        } else {
          break;
        }
      }
    }
    return idx;
  }
};

int main() { return 0; }
