#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> counts(10);
    for (const auto digit : digits) {
      ++counts[digit];
    }
    vector<int> result;
    for (int i = 1; i < 10; ++i) {
      if (counts[i] == 0) {
        continue;
      }
      --counts[i];
      int num = i;
      for (int j = 0; j < 10; ++j) {
        if (counts[j] == 0) {
          continue;
        }
        --counts[j];
        num = num * 10 + j;
        for (int k = 0; k < 10; k += 2) {
          if (counts[k] == 0) {
            continue;
          }
          num = num * 10 + k;
          result.push_back(num);
          num /= 10;
        }
        ++counts[j];
        num /= 10;
      }
      ++counts[i];
      num /= 10;
    }
    return result;
  }
};
