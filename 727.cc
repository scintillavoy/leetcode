#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string minWindow(string s1, string s2) {
    int start = -1, end = s1.size();
    vector<int> starting_indices(s2.size(), -1);
    for (int i = 0; i < s1.size(); ++i) {
      for (int j = s2.size() - 1; j >= 0; --j) {
        if (s1[i] != s2[j]) {
          continue;
        }
        if (j == 0) {
          starting_indices[j] = i;
        } else if (starting_indices[j - 1] != -1) {
          starting_indices[j] = starting_indices[j - 1];
        }
        if (j + 1 == s2.size() && starting_indices[j] != -1 &&
            i - starting_indices[j] < end - start) {
          start = starting_indices[j];
          end = i;
        }
      }
    }
    if (start == -1) {
      return "";
    }
    return s1.substr(start, end - start + 1);
  }
};
