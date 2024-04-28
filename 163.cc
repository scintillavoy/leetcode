#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> findMissingRanges(vector<int>& nums, int lower,
                                        int upper) {
    vector<vector<int>> answer;
    int curr = lower;
    for (const auto num : nums) {
      if (curr < num) {
        answer.push_back({curr, num - 1});
      }
      curr = num + 1;
    }
    if (curr <= upper) {
      answer.push_back({curr, upper});
    }
    return answer;
  }
};
