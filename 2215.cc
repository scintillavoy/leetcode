#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> result(2);
    unordered_set<int> s1, s2;
    for (const auto num : nums1) {
      s1.insert(num);
    }
    for (const auto num : nums2) {
      s2.insert(num);
    }
    for (const auto num : s1) {
      if (s2.count(num) == 0) {
        result[0].push_back(num);
      }
    }
    for (const auto num : s2) {
      if (s1.count(num) == 0) {
        result[1].push_back(num);
      }
    }
    return result;
  }
};
