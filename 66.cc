#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int index = digits.size() - 1;
    while (index >= 0 && digits[index] == 9) {
      digits[index] = 0;
      --index;
    }
    if (index >= 0) {
      ++digits[index];
    } else {
      digits[0] = 1;
      digits.push_back(0);
    }
    return digits;
  }
};
