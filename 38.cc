#include <string>
using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string current = "1";
    for (int i = 2; i <= n; ++i) {
      string next;
      int count = 1;
      for (int j = 1; j <= current.size(); ++j) {
        if (j == current.size() || current[j - 1] != current[j]) {
          next += to_string(count) + current[j - 1];
          count = 1;
        } else {
          ++count;
        }
      }
      current = next;
    }
    return current;
  }
};
