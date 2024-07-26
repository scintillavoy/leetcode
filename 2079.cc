#include <vector>
using namespace std;

class Solution {
 public:
  int wateringPlants(vector<int>& plants, int capacity) {
    int result = 0;
    int water = capacity;
    for (int i = 0; i < plants.size(); ++i) {
      if (water < plants[i]) {
        result += 2 * i;
        water = capacity;
      }
      ++result;
      water -= plants[i];
    }
    return result;
  }
};
