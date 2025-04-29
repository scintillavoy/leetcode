#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> frequencies;
    for (const auto num : nums) {
      if (num % 2 == 0) {
        ++frequencies[num];
      }
    }
    int max_frequency = 0;
    int most_frequent = -1;
    for (const auto [num, frequency] : frequencies) {
      if (max_frequency < frequency) {
        max_frequency = frequency;
        most_frequent = num;
      } else if (max_frequency == frequency) {
        most_frequent = min(most_frequent, num);
      }
    }
    return most_frequent;
  }
};
