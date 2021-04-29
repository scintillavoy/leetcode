#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int idx = digits.size() - 1;
    while (idx >= 0 && digits[idx] == 9) {
      digits[idx] = 0;
      --idx;
    }
    if (idx >= 0) {
      ++digits[idx];
    } else {
      digits[0] = 1;
      digits.push_back(0);
    }
    return digits;
  }
};

int main() { return 0; }
