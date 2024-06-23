#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    if (hour <= dist.size() - 1) {
      return -1;
    }
    int start = 1, end = 1e7;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      double time = 0.0;
      for (int i = 0; i < dist.size() - 1; ++i) {
        time += ceil((double)dist[i] / mid);
      }
      time += (double)dist.back() / mid;
      if (time <= hour) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
