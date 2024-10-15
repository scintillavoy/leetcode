#include <string>
using namespace std;

class Solution {
 public:
  long long minimumSteps(string s) {
    int num_of_zeros = 0;
    long long min_steps = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        min_steps += i - num_of_zeros;
        ++num_of_zeros;
      }
    }
    return min_steps;
  }
};
