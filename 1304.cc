#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> result;
    int sum = 0;
    for (int i = 1; i < n; ++i) {
      result.push_back(i);
    }
    result.push_back(-n * (n - 1) / 2);
    return result;
  }
};
