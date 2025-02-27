#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(n));
    int max_length = 0;
    for (int i = 2; i < n; ++i) {
      int left = 0, right = i - 1;
      while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == arr[i]) {
          memo[right][i] = max(memo[right][i], memo[left][right] + 1);
          max_length = max(max_length, memo[right][i]);
          ++left;
          --right;
        } else if (sum < arr[i]) {
          ++left;
        } else {
          --right;
        }
      }
    }
    return max_length > 0 ? max_length + 2 : 0;
  }
};
