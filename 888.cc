#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    unordered_set<int> alice_set;
    int diff = 0;
    for (const auto size : aliceSizes) {
      alice_set.insert(size);
      diff += size;
    }
    for (const auto size : bobSizes) {
      diff -= size;
    }
    if (diff % 2 != 0) {
      return {-1, -1};
    }
    for (const auto size : bobSizes) {
      if (alice_set.contains(size + diff / 2)) {
        return {size + diff / 2, size};
      }
    }
    return {-1, -1};
  }
};
