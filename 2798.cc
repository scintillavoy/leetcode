#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int result = 0;
    for (const auto hour : hours) {
      if (hour >= target) {
        ++result;
      }
    }
    return result;
  }
};
