#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxJumps(vector<int>& arr, int d) {
    int n = arr.size();
    vector<int> max_jumps(n);
    for (int i = 0; i < n; ++i) {
      traverse(arr, max_jumps, i, d);
    }
    return *max_element(max_jumps.begin(), max_jumps.end());
  }

 private:
  void traverse(vector<int>& arr, vector<int>& max_jumps, int curr, int d) {
    if (max_jumps[curr] != 0) {
      return;
    }
    max_jumps[curr] = 1;

    for (int i = 1; i <= d; ++i) {
      int next = curr - i;
      if (next < 0 || arr[next] >= arr[curr]) {
        break;
      }
      traverse(arr, max_jumps, next, d);
      max_jumps[curr] = max(max_jumps[curr], max_jumps[next] + 1);
    }

    for (int i = 1; i <= d; ++i) {
      int next = curr + i;
      if (next >= arr.size() || arr[next] >= arr[curr]) {
        break;
      }
      traverse(arr, max_jumps, next, d);
      max_jumps[curr] = max(max_jumps[curr], max_jumps[next] + 1);
    }
  }
};
