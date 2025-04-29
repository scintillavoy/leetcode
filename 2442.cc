#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int countDistinctIntegers(vector<int>& nums) {
    unordered_set<int> num_set;
    for (const auto num : nums) {
      num_set.insert(num);
      num_set.insert(reverse_num(num));
    }
    return num_set.size();
  }

 private:
  int reverse_num(int num) {
    int reversed = 0;
    while (num > 0) {
      reversed = reversed * 10 + num % 10;
      num /= 10;
    }
    return reversed;
  }
};
