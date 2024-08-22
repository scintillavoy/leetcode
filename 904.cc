#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> counts;
    int left = 0;
    int max_fruits = 0;
    for (int right = 0; right < fruits.size(); ++right) {
      ++counts[fruits[right]];
      while (counts.size() > 2) {
        --counts[fruits[left]];
        if (counts[fruits[left]] == 0) {
          counts.erase(fruits[left]);
        }
        ++left;
      }
      max_fruits = max(max_fruits, right - left + 1);
    }
    return max_fruits;
  }
};
