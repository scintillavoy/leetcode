#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int removal_count = arr.size() / 20;
    int sum = 0;
    for (int i = removal_count; i < arr.size() - removal_count; ++i) {
      sum += arr[i];
    }
    return (double)sum / (arr.size() - removal_count * 2);
  }
};
