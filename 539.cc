#include <algorithm>
#include <limits>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    int min_difference = numeric_limits<int>::max();
    for (int i = 1; i < timePoints.size(); ++i) {
      int difference = get_difference(timePoints[i - 1], timePoints[i]);
      min_difference = min(min_difference, difference);
    }
    min_difference =
        min(min_difference,
            1440 - get_difference(timePoints.front(), timePoints.back()));
    return min_difference;
  }

 private:
  int get_difference(string& a, string& b) {
    int a_in_minutes = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3));
    int b_in_minutes = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(3));
    return b_in_minutes - a_in_minutes;
  }
};
