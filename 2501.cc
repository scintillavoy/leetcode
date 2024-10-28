#include <algorithm>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    int max_num = *max_element(nums.begin(), nums.end());
    parents = vector<int>(max_num + 1);
    for (int i = 0; i < parents.size(); ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(max_num + 1);
    sizes = vector<int>(max_num + 1, 1);
    unordered_set<int> num_set(nums.begin(), nums.end());
    int max_size = 1;
    for (int i = 0; i < nums.size(); ++i) {
      long long square = (long long)nums[i] * nums[i];
      if (square <= max_num && num_set.contains(square)) {
        max_size = max(max_size, union_set(nums[i], square));
      }
    }
    return max_size == 1 ? -1 : max_size;
  }

 private:
  vector<int> parents;
  vector<int> ranks;
  vector<int> sizes;

  int find_set(int x) {
    if (parents[x] != x) {
      parents[x] = find_set(parents[x]);
    }
    return parents[x];
  }

  int union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return sizes[y];
    }
    if (ranks[x] > ranks[y]) {
      swap(x, y);
    } else if (ranks[x] == ranks[y]) {
      ++ranks[y];
    }
    parents[x] = y;
    sizes[y] += sizes[x];
    return sizes[y];
  }
};
