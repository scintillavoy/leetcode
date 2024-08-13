#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start,
                              int destination) {
    int n = distance.size();
    int distance_clockwise = 0, distance_ccw = 0;
    for (int i = start; i != destination; i = (i + 1) % n) {
      distance_clockwise += distance[i];
    }
    for (int i = destination; i != start; i = (i + 1) % n) {
      distance_ccw += distance[i];
    }
    return min(distance_clockwise, distance_ccw);
  }
};
