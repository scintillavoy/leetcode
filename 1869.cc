#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkZeroOnes(string s) {
    vector<int> max_lengths(2);
    int length = 1;
    for (int i = 1; i <= s.size(); ++i) {
      if (i == s.size() || s[i - 1] != s[i]) {
        int index = s[i - 1] - '0';
        max_lengths[index] = max(max_lengths[index], length);
        length = 1;
      } else {
        ++length;
      }
    }
    return max_lengths[0] < max_lengths[1];
  }
};
