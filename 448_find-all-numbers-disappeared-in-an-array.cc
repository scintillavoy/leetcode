#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
      while (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    vector<int> sol;
    for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        sol.push_back(i + 1);
      }
    }
    return sol;
  }
};

int main() {
  Solution sol;
  return 0;
}
