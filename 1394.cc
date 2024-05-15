#include <vector>
using namespace std;

class Solution {
 public:
  int findLucky(vector<int>& arr) {
    vector<int> frequency(501);
    for (const auto num : arr) {
      ++frequency[num];
    }
    for (int i = 500; i > 0; --i) {
      if (frequency[i] == i) {
        return i;
      }
    }
    return -1;
  }
};
