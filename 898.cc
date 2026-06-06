#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> total_set;
    unordered_set<int> prev_set;
    for (const auto num : arr) {
      unordered_set<int> curr_set;
      for (const auto bit : prev_set) {
        curr_set.insert(bit | num);
      }
      curr_set.insert(num);
      for (const auto bit : curr_set) {
        total_set.insert(bit);
      }
      prev_set = curr_set;
    }
    return total_set.size();
  }
};
