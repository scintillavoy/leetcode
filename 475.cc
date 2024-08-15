#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int low = 0, high = max({abs(heaters.front() - houses.front()),
                             abs(heaters.front() - houses.back()),
                             abs(heaters.back() - houses.front()),
                             abs(heaters.back() - houses.back())});
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int house = 0, heater = 0;
      while (house < houses.size() && heater < heaters.size()) {
        while (house < houses.size() &&
               abs(houses[house] - heaters[heater]) <= mid) {
          ++house;
        }
        ++heater;
      }
      if (house >= houses.size()) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};
