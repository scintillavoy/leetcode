#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> new_nums;
    for (int i = 0; i < n; ++i) {
      string num_str = to_string(nums[i]);
      int new_num = 0;
      for (const auto c : num_str) {
        new_num = new_num * 10 + mapping[c - '0'];
      }
      new_nums.push_back({new_num, i});
    }
    sort(new_nums.begin(), new_nums.end(),
         [](const pair<int, int> a, const pair<int, int> b) {
           if (a.first != b.first) {
             return a.first < b.first;
           }
           return a.second < b.second;
         });
    vector<int> result;
    for (int i = 0; i < n; ++i) {
      result.push_back(nums[new_nums[i].second]);
    }
    return result;
  }
};
