#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int num_of_apples = 0;
    for (const auto a : apple) {
      num_of_apples += a;
    }
    sort(capacity.rbegin(), capacity.rend());
    for (int i = 0; i < capacity.size(); ++i) {
      num_of_apples -= capacity[i];
      if (num_of_apples <= 0) {
        return i + 1;
      }
    }
    return -1;
  }
};
