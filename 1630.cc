#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                        vector<int>& r) {
    vector<bool> result(l.size());
    for (int i = 0; i < l.size(); ++i) {
      int left = l[i];
      int right = r[i];
      vector<int> subarray(right - left + 1);
      for (int j = left; j <= right; ++j) {
        subarray[j - left] = nums[j];
      }
      sort(subarray.begin(), subarray.end());
      int diff = subarray[1] - subarray[0];
      bool valid = true;
      for (int i = 2; i < subarray.size(); ++i) {
        if (diff != subarray[i] - subarray[i - 1]) {
          valid = false;
          break;
        }
      }
      result[i] = valid;
    }
    return result;
  }
};
