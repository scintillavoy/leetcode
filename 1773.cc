#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int countMatches(vector<vector<string>>& items, string ruleKey,
                   string ruleValue) {
    int value_index;
    if (ruleKey == "type") {
      value_index = 0;
    } else if (ruleKey == "color") {
      value_index = 1;
    } else if (ruleKey == "name") {
      value_index = 2;
    } else {
      return -1;
    }
    int count = 0;
    for (const auto& item : items) {
      if (item[value_index] == ruleValue) {
        ++count;
      }
    }
    return count;
  }
};
