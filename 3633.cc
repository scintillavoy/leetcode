#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                         vector<int>& waterStartTime,
                         vector<int>& waterDuration) {
    int land = numeric_limits<int>::max();
    for (int i = 0; i < landStartTime.size(); ++i) {
      land = min(land, landStartTime[i] + landDuration[i]);
    }
    int water = numeric_limits<int>::max();
    int land_water = numeric_limits<int>::max();
    for (int i = 0; i < waterStartTime.size(); ++i) {
      water = min(water, waterStartTime[i] + waterDuration[i]);
      land_water =
          min(land_water, max(land, waterStartTime[i]) + waterDuration[i]);
    }
    int water_land = numeric_limits<int>::max();
    for (int i = 0; i < landStartTime.size(); ++i) {
      water_land =
          min(water_land, max(water, landStartTime[i]) + landDuration[i]);
    }
    return min(land_water, water_land);
  }
};
