#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string convertDateToBinary(string date) {
    string result;
    vector<int> nums = {
        stoi(date.substr(0, 4)),
        stoi(date.substr(5, 2)),
        stoi(date.substr(8, 2)),
    };
    for (auto num : nums) {
      string token;
      while (num > 0) {
        token += (num & 1) + '0';
        num >>= 1;
      }
      reverse(token.begin(), token.end());
      result += token + '-';
    }
    result.pop_back();
    return result;
  }
};
