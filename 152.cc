#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> remaining_negatives(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] > 0) {
        remaining_negatives[i] = remaining_negatives[i + 1];
      } else if (nums[i] == 0) {
        remaining_negatives[i] = 0;
      } else {
        remaining_negatives[i] = remaining_negatives[i + 1] + 1;
      }
    }
    int current_product = 1;
    int max_product = *max_element(nums.cbegin(), nums.cend());
    int current_negatives = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
      if (nums[right] > 0) {
        current_product *= nums[right];
        max_product = max(max_product, current_product);
      } else if (nums[right] == 0) {
        current_product = 1;
        max_product = max(max_product, 0);
        current_negatives = 0;
        left = right + 1;
      } else {
        if (remaining_negatives[right] <= 1 && current_negatives % 2 == 0) {
          while (left < right) {
            current_product /= nums[left];
            if (nums[left] < 0) {
              --current_negatives;
              break;
            }
            ++left;
          }
          if (left == right) {
            ++left;
            continue;
          }
        }
        current_product *= nums[right];
        max_product = max(max_product, current_product);
        ++current_negatives;
      }
    }
    return max_product;
  }
};
