#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int max_product = nums[0];
    int product = 1;
    for (int i = 0; i < nums.size(); ++i) {
      product *= nums[i];
      max_product = max(max_product, product);
      if (product == 0) {
        product = 1;
      }
    }
    product = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      product *= nums[i];
      max_product = max(max_product, product);
      if (product == 0) {
        product = 1;
      }
    }
    return max_product;
  }
};
