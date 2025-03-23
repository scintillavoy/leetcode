#include <vector>
using namespace std;

class Solution {
 public:
  int countTestedDevices(vector<int>& batteryPercentages) {
    int num_of_tests = 0;
    for (const auto battery_percentage : batteryPercentages) {
      if (battery_percentage - num_of_tests > 0) {
        ++num_of_tests;
      }
    }
    return num_of_tests;
  }
};
