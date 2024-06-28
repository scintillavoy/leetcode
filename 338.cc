#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> result;
    result.push_back(0);
    while (result.size() < n + 1) {
      int size = result.size();
      for (int i = 0; i < size; ++i) {
        result.push_back(result[i] + 1);
        if (result.size() == n + 1) {
          break;
        }
      }
    }
    return result;
  }
};
