#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> counts;
    int answer = 0;
    for (const auto num : nums) {
      answer += counts[num];
      ++counts[num];
    }
    return answer;
  }
};
