#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string smallestSubsequence(string s) {
    vector<int> last_index(26, -1);
    for (int i = 0; i < s.size(); ++i) {
      last_index[s[i] - 'a'] = i;
    }
    vector<bool> exist(26);
    string result;
    for (int i = 0; i < s.size(); ++i) {
      if (exist[s[i] - 'a']) {
        continue;
      }
      while (!result.empty() && result.back() >= s[i] &&
             i <= last_index[result.back() - 'a']) {
        exist[result.back() - 'a'] = false;
        result.pop_back();
      }
      exist[s[i] - 'a'] = true;
      result.push_back(s[i]);
    }
    return result;
  }
};
