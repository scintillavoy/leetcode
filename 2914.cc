#include <string>
using namespace std;

class Solution {
 public:
  int minChanges(string s) {
    int min_changes = 0;
    for (int i = 0; i < s.size(); i += 2) {
      if (s[i] != s[i + 1]) {
        ++min_changes;
      }
    }
    return min_changes;
  }
};
