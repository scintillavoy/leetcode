#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool digitCount(string num) {
    vector<int> counts(10);
    for (int i = 0; i < num.size(); ++i) {
      counts[i] += num[i] - '0';
      --counts[num[i] - '0'];
    }
    for (int i = 0; i < counts.size(); ++i) {
      if (counts[i] != 0) {
        return false;
      }
    }
    return true;
  }
};
