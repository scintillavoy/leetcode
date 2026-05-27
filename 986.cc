#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    vector<vector<int>> intersections;
    int first_index = 0;
    int second_index = 0;
    while (first_index < firstList.size() && second_index < secondList.size()) {
      int low = max(firstList[first_index][0], secondList[second_index][0]);
      int high = min(firstList[first_index][1], secondList[second_index][1]);
      if (low <= high) {
        intersections.push_back({low, high});
      }
      if (firstList[first_index][1] < secondList[second_index][1]) {
        ++first_index;
      } else if (firstList[first_index][1] > secondList[second_index][1]) {
        ++second_index;
      } else {
        ++first_index;
        ++second_index;
      }
    }
    return intersections;
  }
};
