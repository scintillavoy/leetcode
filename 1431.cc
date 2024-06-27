#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int greatest = *max_element(candies.cbegin(), candies.cend());
    vector<bool> result;
    for (const auto candy : candies) {
      result.push_back(candy + extraCandies >= greatest);
    }
    return result;
  }
};
