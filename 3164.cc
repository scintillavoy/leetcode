#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    long long num_of_pairs = 0;
    unordered_map<int, int> nums2_count;
    for (const auto num : nums2) {
      ++nums2_count[num * k];
    }
    for (const auto num : nums1) {
      for (int i = 1; i * i <= num; ++i) {
        if (num % i != 0) {
          continue;
        }
        num_of_pairs += nums2_count[i];
        if (i * i != num) {
          num_of_pairs += nums2_count[num / i];
        }
      }
    }
    return num_of_pairs;
  }
};
