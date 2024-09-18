#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string largestNumber(vector<int> &nums) {
    vector<string> nums_in_string;
    for (const auto num : nums) {
      nums_in_string.push_back(to_string(num));
    }
    sort(nums_in_string.begin(), nums_in_string.end(),
         [](const string &a, const string &b) { return a + b > b + a; });
    if (nums_in_string[0] == "0") {
      return "0";
    }
    string result;
    for (const auto &num : nums_in_string) {
      result += num;
    }
    return result;
  }
};
