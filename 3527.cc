#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  string findCommonResponse(vector<vector<string>>& responses) {
    unordered_map<string, int> response_counts;
    for (int i = 0; i < responses.size(); ++i) {
      unordered_set<string> response_set;
      for (const auto& response : responses[i]) {
        response_set.insert(response);
      }
      for (const auto& response : response_set) {
        ++response_counts[response];
      }
    }
    int max_count = 0;
    string result;
    for (const auto& [response, count] : response_counts) {
      if (max_count < count || max_count == count && response < result) {
        max_count = count;
        result = response;
      }
    }
    return result;
  }
};
