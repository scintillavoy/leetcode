#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  string reverseStr(string s, int k) {
    int n = s.size();
    int i = 0;
    string reversed;
    while (i < n) {
      int low = i;
      int high = min(i + k - 1, n - 1);
      for (int j = high; j >= low; --j) {
        reversed.push_back(s[j]);
      }
      for (int j = 1; j <= k; ++j) {
        if (high + j >= n) {
          return reversed;
        }
        reversed.push_back(s[high + j]);
      }
      i += 2 * k;
    }
    return reversed;
  }
};
