#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    int num_of_removals = 0;
    int num_of_opens = 0;
    for (const auto ch : s) {
      if (ch == '(') {
        ++num_of_opens;
      } else if (ch == ')') {
        if (num_of_opens == 0) {
          ++num_of_removals;
        } else {
          --num_of_opens;
        }
      }
    }
    num_of_removals += num_of_opens;
    unordered_set<string> result;
    string curr_str;
    backtrack(s, result, 0, curr_str, num_of_removals, 0);
    return vector<string>(result.begin(), result.end());
  }

 private:
  void backtrack(string& s, unordered_set<string>& result, int s_idx,
                 string& curr_str, int num_of_removals, int num_of_opens) {
    if (s_idx == s.size()) {
      if (num_of_removals == 0 && num_of_opens == 0) {
        result.insert(curr_str);
      }
      return;
    }
    if (s[s_idx] == '(') {
      if (num_of_removals > 0) {
        backtrack(s, result, s_idx + 1, curr_str, num_of_removals - 1,
                  num_of_opens);
      }
      curr_str.push_back(s[s_idx]);
      backtrack(s, result, s_idx + 1, curr_str, num_of_removals,
                num_of_opens + 1);
      curr_str.pop_back();
    } else if (s[s_idx] == ')') {
      if (num_of_removals > 0) {
        backtrack(s, result, s_idx + 1, curr_str, num_of_removals - 1,
                  num_of_opens);
      }
      if (num_of_opens > 0) {
        curr_str.push_back(s[s_idx]);
        backtrack(s, result, s_idx + 1, curr_str, num_of_removals,
                  num_of_opens - 1);
        curr_str.pop_back();
      }
    } else {
      curr_str.push_back(s[s_idx]);
      backtrack(s, result, s_idx + 1, curr_str, num_of_removals, num_of_opens);
      curr_str.pop_back();
    }
  }
};
