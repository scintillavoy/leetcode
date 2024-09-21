#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    vector<int> kmp_table(needle.size());
    for (int i = 1, j = 0; i < needle.size(); ++i) {
      while (j > 0 && needle[i] != needle[j]) {
        j = kmp_table[j - 1];
      }
      if (needle[i] == needle[j]) {
        ++j;
      }
      kmp_table[i] = j;
    }
    for (int i = 0, j = 0; i < haystack.size(); ++i) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = kmp_table[j - 1];
      }
      if (haystack[i] == needle[j]) {
        ++j;
        if (j == needle.size()) {
          return i + 1 - j;
        }
      }
    }
    return -1;
  }
};
