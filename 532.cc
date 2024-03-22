#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int findPairs(vector<int> &nums, int k) {
    unordered_map<int, int> frequency;
    unordered_set<int> counted;
    for (const auto &num : nums) {
      ++frequency[num];
    }
    int answer = 0;
    for (const auto &num : nums) {
      if (counted.count(num) != 0) {
        continue;
      }
      if (k == 0) {
        if (frequency[num + k] >= 2) {
          ++answer;
        }
      } else {
        if (frequency[num + k] != 0) {
          ++answer;
        }
      }
      counted.insert(num);
    }
    return answer;
  }
};
