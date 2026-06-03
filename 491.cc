#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> subsequences;
    vector<int> curr_seq;
    backtrack(nums, 0, subsequences, curr_seq);
    return subsequences;
  }

 private:
  void backtrack(const vector<int>& nums, int index,
                 vector<vector<int>>& subsequences, vector<int>& curr_seq) {
    if (index == nums.size()) {
      if (curr_seq.size() >= 2) {
        subsequences.push_back(curr_seq);
      }
      return;
    }
    if (curr_seq.empty() || curr_seq.back() <= nums[index]) {
      curr_seq.push_back(nums[index]);
      backtrack(nums, index + 1, subsequences, curr_seq);
      curr_seq.pop_back();
    }
    if (curr_seq.empty() || curr_seq.back() != nums[index]) {
      backtrack(nums, index + 1, subsequences, curr_seq);
    }
  }
};
