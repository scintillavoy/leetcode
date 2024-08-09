#include <vector>
using namespace std;

class Solution {
 public:
  int reversePairs(vector<int> &nums) {
    vector<int> temp(nums.size());
    return merge_sort(nums, 0, nums.size() - 1, temp);
  }

 private:
  int merge_sort(vector<int> &nums, int left, int right, vector<int> &temp) {
    if (left >= right) {
      return 0;
    }
    int mid = left + (right - left) / 2;
    int result = merge_sort(nums, left, mid, temp) +
                 merge_sort(nums, mid + 1, right, temp);
    result += count_pairs(nums, left, mid, right);
    merge(nums, left, mid, right, temp);
    return result;
  }

  int count_pairs(const vector<int> &nums, int left, int mid, int right) {
    int count = 0;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
      if (nums[i] > 2LL * nums[j]) {
        count += mid - i + 1;
        ++j;
      } else {
        ++i;
      }
    }
    return count;
  }

  void merge(vector<int> &nums, int left, int mid, int right,
             vector<int> &temp) {
    for (int i = left; i <= right; ++i) {
      temp[i] = nums[i];
    }

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
      if (temp[i] <= temp[j]) {
        nums[k] = temp[i];
        ++i;
      } else {
        nums[k] = temp[j];
        ++j;
      }
      ++k;
    }

    while (i <= mid) {
      nums[k] = temp[i];
      ++i;
      ++k;
    }
    while (j <= right) {
      nums[k] = temp[j];
      ++j;
      ++k;
    }
  }
};
