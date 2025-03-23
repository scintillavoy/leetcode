#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int finalValueAfterOperations(vector<string>& operations) {
    int value = 0;
    for (const auto& operation : operations) {
      if (operation.front() == '+' || operation.back() == '+') {
        ++value;
      } else {
        --value;
      }
    }
    return value;
  }
};
