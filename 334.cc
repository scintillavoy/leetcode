#include <vector>
using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    vector<int> subsequence;
    for (const auto num : nums) {
      if (subsequence.empty() || subsequence.back() < num) {
        subsequence.push_back(num);
        if (subsequence.size() == 3) {
          return true;
        }
      } else {
        for (int i = 0; i < subsequence.size(); ++i) {
          if (subsequence[i] >= num) {
            subsequence[i] = num;
            break;
          }
        }
      }
    }
    return false;
  }
};
