#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                   int x) {
    vector<int> occurrences;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == x) {
        occurrences.push_back(i);
      }
    }
    vector<int> result;
    for (const auto query : queries) {
      if (occurrences.size() < query) {
        result.push_back(-1);
      } else {
        result.push_back(occurrences[query - 1]);
      }
    }
    return result;
  }
};
