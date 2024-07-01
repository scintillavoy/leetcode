#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> counts;
    for (const auto num : arr) {
      ++counts[num];
    }
    unordered_set<int> s;
    for (const auto count : counts) {
      if (s.count(count.second) != 0) {
        return false;
      }
      s.insert(count.second);
    }
    return true;
  }
};
