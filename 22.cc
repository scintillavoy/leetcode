#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string curr;
    backtrack(n, 0, curr, result);
    return result;
  }

 private:
  void backtrack(int open, int close, string &curr, vector<string> &result) {
    if (open == 0 && close == 0) {
      result.push_back(curr);
      return;
    }
    if (open > 0) {
      curr.push_back('(');
      backtrack(open - 1, close + 1, curr, result);
      curr.pop_back();
    }
    if (close > 0) {
      curr.push_back(')');
      backtrack(open, close - 1, curr, result);
      curr.pop_back();
    }
  }
};
