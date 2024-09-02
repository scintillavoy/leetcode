#include <vector>
using namespace std;

class Solution {
 public:
  int chalkReplacer(vector<int>& chalk, int k) {
    long long sum = 0;
    for (int i = 0; i < chalk.size(); ++i) {
      sum += chalk[i];
    }
    int quotient = (k - chalk[0]) / sum;
    for (int i = 0; i < chalk.size(); ++i) {
      k -= chalk[i];
      int next_quotient = k / sum;
      if (k < 0 || quotient > next_quotient) {
        return i;
      }
    }
    return 0;
  }
};
