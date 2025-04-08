#include <vector>
using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_sum_of_diffs = 0;
    int current_sum_of_diffs = 0;
    int candidate = 0;
    for (int i = 0; i < gas.size(); ++i) {
      total_sum_of_diffs += gas[i] - cost[i];
      current_sum_of_diffs += gas[i] - cost[i];
      if (current_sum_of_diffs < 0) {
        current_sum_of_diffs = 0;
        candidate = i + 1;
      }
    }
    if (total_sum_of_diffs < 0) {
      return -1;
    }
    return candidate;
  }
};
