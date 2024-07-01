#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;
    for (const auto asteroid : asteroids) {
      bool should_push = true;
      while (!result.empty() && result.back() > 0 && asteroid < 0) {
        if (result.back() < -asteroid) {
          result.pop_back();
        } else if (result.back() > -asteroid) {
          should_push = false;
          break;
        } else {
          result.pop_back();
          should_push = false;
          break;
        }
      }
      if (should_push) {
        result.push_back(asteroid);
      }
    }
    return result;
  }
};
