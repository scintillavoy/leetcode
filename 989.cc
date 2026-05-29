#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> result;
    int carry = 0;
    int i = num.size() - 1;
    while (i >= 0 || k > 0) {
      result.push_back(k % 10 + carry);
      if (i >= 0) {
        result.back() += num[i];
      }
      k /= 10;
      carry = result.back() / 10;
      result.back() %= 10;
      --i;
    }
    if (carry > 0) {
      result.push_back(carry);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
