#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> separateDigits(vector<int>& nums) {
    vector<int> result;
    for (auto num : nums) {
      vector<int> digits;
      while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
      }
      while (!digits.empty()) {
        result.push_back(digits.back());
        digits.pop_back();
      }
    }
    return result;
  }
};
