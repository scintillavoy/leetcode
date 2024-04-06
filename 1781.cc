#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int beautySum(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); ++i) {
      vector<int> count(26);
      int max_count = 0, min_count = 0;
      for (int j = i; j < s.size(); ++j) {
        ++count[s[j] - 'a'];
        max_count = max(max_count, count[s[j] - 'a']);
        if (min_count >= count[s[j] - 'a'] - 1) {
          min_count = count[s[j] - 'a'];
          for (int k = 0; k < 26; ++k) {
            if (count[k] == 0) {
              continue;
            }
            min_count = min(min_count, count[k]);
          }
        }
        answer += max_count - min_count;
      }
    }
    return answer;
  }
};
