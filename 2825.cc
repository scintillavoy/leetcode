#include <string>
using namespace std;

class Solution {
 public:
  bool canMakeSubsequence(string str1, string str2) {
    int idx1 = 0, idx2 = 0;
    while (idx1 < str1.size() && idx2 < str2.size()) {
      if (str1[idx1] == str2[idx2] ||
          (str1[idx1] == 'z' && str2[idx2] == 'a') ||
          str1[idx1] + 1 == str2[idx2]) {
        ++idx2;
      }
      ++idx1;
    }
    return idx2 == str2.size();
  }
};
