#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    sort(asteroids.begin(), asteroids.end());
    long long current_mass = mass;
    int i = 0;
    while (i < asteroids.size() && current_mass >= asteroids[i]) {
      current_mass += asteroids[i];
      ++i;
    }
    return i == asteroids.size();
  }
};
