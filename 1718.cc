#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> constructDistancedSequence(int n) {
    vector<int> sequence(1 + (n - 1) * 2);
    unordered_set<int> used_nums;
    backtrack(sequence, n, 0, used_nums);
    return sequence;
  }

 private:
  bool backtrack(vector<int> &sequence, int n, int index,
                 unordered_set<int> &used_nums) {
    if (index == sequence.size()) {
      return true;
    }
    if (sequence[index] != 0) {
      return backtrack(sequence, n, index + 1, used_nums);
    }
    for (int i = n; i > 0; --i) {
      if (used_nums.contains(i) ||
          i > 1 && (index + i >= sequence.size() || sequence[index + i] != 0)) {
        continue;
      }
      sequence[index] = i;
      if (i != 1) {
        sequence[index + i] = i;
      }
      used_nums.insert(i);
      if (backtrack(sequence, n, index + 1, used_nums)) {
        return true;
      }
      sequence[index] = 0;
      if (i != 1) {
        sequence[index + i] = 0;
      }
      used_nums.erase(i);
    }
    return false;
  }
};
