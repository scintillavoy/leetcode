#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    string num;
    for (int i = 0; i < nums.size(); ++i) {
      num.push_back(nums[i][i] == '0' ? '1' : '0');
    }
    return num;
  }
};
