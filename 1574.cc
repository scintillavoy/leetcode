#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int right = arr.size() - 1;
    while (right > 0 && arr[right - 1] <= arr[right]) {
      --right;
    }
    int min_length = right;
    for (int left = 0;
         left < right && (left == 0 || arr[left - 1] <= arr[left]); ++left) {
      while (right < arr.size() && arr[left] > arr[right]) {
        ++right;
      }
      min_length = min(min_length, right - left - 1);
    }
    return min_length;
  }
};
