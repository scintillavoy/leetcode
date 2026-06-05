#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestMountain(vector<int>& arr) {
    int max_length = 0;
    int i = 0;
    while (i + 1 < arr.size()) {
      int left = i;
      while (i + 1 < arr.size() && arr[i] < arr[i + 1]) {
        ++i;
      }
      int peak = i;
      while (i + 1 < arr.size() && arr[i] > arr[i + 1]) {
        ++i;
      }
      int right = i;
      if (left < peak && peak < right) {
        max_length = max(max_length, right - left + 1);
      }
      if (left == right) {
        ++i;
      }
    }
    return max_length;
  }
};
