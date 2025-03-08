#include <vector>
using namespace std;

class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    int consecutive_count = 1;
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] == arr[i - 1]) {
        ++consecutive_count;
        if (consecutive_count > arr.size() / 4) {
          return arr[i];
        }
      } else {
        consecutive_count = 1;
      }
    }
    return arr[0];
  }
};
