#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> result;
    int curr = 1;
    while (curr > 0) {
      if (curr <= n) {
        result.push_back(curr);
        curr *= 10;
      } else {
        curr /= 10;
        while (curr % 10 == 9) {
          curr /= 10;
        }
        if (curr == 0) {
          break;
        }
        ++curr;
      }
    }
    return result;
  }
};
