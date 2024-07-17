#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int countCompleteDayPairs(vector<int>& hours) {
    unordered_map<int, int> counts;
    int result = 0;
    for (const auto hour : hours) {
      result += counts[(24 - hour % 24) % 24];
      ++counts[hour % 24];
    }
    return result;
  }
};
