#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long countPairs(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> diff(n);
    for (int i = 0; i < n; ++i) {
      diff[i] = nums1[i] - nums2[i];
    }
    sort(diff.begin(), diff.end());
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
      int left = i + 1, right = n - 1;
      while (left <= right) {
        int mid = (left + right) / 2;
        int value = diff[i] + diff[mid];
        if (value > 0) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      answer += n - left;
    }
    return answer;
  }
};
