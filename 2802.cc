#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  string kthLuckyNumber(int k) {
    --k;
    string result;
    int denominator = 1;
    while (k >= 0) {
      if ((k / denominator) % 2 == 0) {
        result.push_back('4');
      } else {
        result.push_back('7');
      }
      denominator *= 2;
      k -= denominator;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
