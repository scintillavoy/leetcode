#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    int num_of_tuples = 0;
    unordered_map<int, int> product_frequencies;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        int product = nums[i] * nums[j];
        num_of_tuples += product_frequencies[product] * 8;
        ++product_frequencies[product];
      }
    }
    return num_of_tuples;
  }
};
