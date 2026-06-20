#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks,
                  int additionalRocks) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < capacity.size(); ++i) {
      pq.push(capacity[i] - rocks[i]);
    }
    int max_bags = 0;
    while (!pq.empty()) {
      int rocks_needed = pq.top();
      pq.pop();
      if (rocks_needed > additionalRocks) {
        break;
      }
      additionalRocks -= rocks_needed;
      ++max_bags;
    }
    return max_bags;
  }
};
