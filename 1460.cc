#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> counts;
    for (const auto num : target) {
      ++counts[num];
    }
    for (const auto num : arr) {
      --counts[num];
    }
    for (const auto [_, v] : counts) {
      if (v != 0) {
        return false;
      }
    }
    return true;
  }
};
