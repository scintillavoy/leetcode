#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> curr;
    backtrack(result, curr, n, k);
    return result;
  }

 private:
  void backtrack(vector<vector<int>> &result, vector<int> &curr, int n, int k) {
    if (curr.size() == k) {
      result.push_back(curr);
      return;
    }
    for (int i = (curr.empty() ? 1 : curr.back() + 1);
         i <= n + 1 - (k - curr.size()); ++i) {
      curr.push_back(i);
      backtrack(result, curr, n, k);
      curr.pop_back();
    }
  }
};
