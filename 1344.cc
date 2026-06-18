#include <algorithm>
using namespace std;

class Solution {
 public:
  double angleClock(int hour, int minutes) {
    double hour_angle = hour * 30 + (double)minutes / 2;
    double minutes_angle = minutes * 6;
    double diff = abs(hour_angle - minutes_angle);
    return min(diff, 360 - diff);
  }
};
