#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int satisfaction = 0;
    for (int i = 0; i < n; ++i) {
      if (grumpy[i] == 0) {
        satisfaction += customers[i];
      }
    }
    int start = 0, end = 0;
    while (end - start < minutes) {
      if (grumpy[end] == 1) {
        satisfaction += customers[end];
      }
      ++end;
    }
    int max_satisfaction = satisfaction;
    while (end < n) {
      if (grumpy[start] == 1) {
        satisfaction -= customers[start];
      }
      ++start;
      if (grumpy[end] == 1) {
        satisfaction += customers[end];
      }
      ++end;
      max_satisfaction = max(max_satisfaction, satisfaction);
    }
    return max_satisfaction;
  }
};
