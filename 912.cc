#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sortArray(vector<int> &nums) {
    vector<int> temp(nums.size());
    merge_sort(nums, 0, nums.size() - 1, temp);
    return nums;
  }

 private:
  void merge_sort(vector<int> &arr, int left, int right, vector<int> &temp) {
    if (left >= right) {
      return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid, temp);
    merge_sort(arr, mid + 1, right, temp);
    merge(arr, left, mid, right, temp);
  }

  void merge(vector<int> &arr, int left, int mid, int right,
             vector<int> &temp) {
    for (int i = left; i <= right; i++) {
      temp[i] = arr[i];
    }

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
      if (temp[i] <= temp[j]) {
        arr[k] = temp[i];
        ++i;
      } else {
        arr[k] = temp[j];
        ++j;
      }
      ++k;
    }

    while (i <= mid) {
      arr[k] = temp[i];
      ++i;
      ++k;
    }
    while (j <= right) {
      arr[k] = temp[j];
      ++j;
      ++k;
    }
  }
};
