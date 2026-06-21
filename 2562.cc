#include <vector>
using namespace std;

class Solution {
 public:
  long long findTheArrayConcVal(vector<int>& nums) {
    long long result = 0;
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
      long long num1 = nums[i];
      int num2 = nums[j];
      while (num2 > 0) {
        num1 *= 10;
        num2 /= 10;
      }
      result += num1 + nums[j];
      ++i;
      --j;
    }
    if (i == j) {
      result += nums[i];
    }
    return result;
  }
};
