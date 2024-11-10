#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                 vector<int>& arr3) {
    vector<int> intersection;
    int idx1 = 0, idx2 = 0, idx3 = 0;
    while (idx1 < arr1.size() && idx2 < arr2.size() && idx3 < arr3.size()) {
      if (arr1[idx1] == arr2[idx2] && arr2[idx2] == arr3[idx3]) {
        intersection.push_back(arr1[idx1]);
        ++idx1;
        ++idx2;
        ++idx3;
        continue;
      }
      int max_num = max({arr1[idx1], arr2[idx2], arr3[idx3]});
      if (arr1[idx1] < max_num) {
        ++idx1;
      }
      if (arr2[idx2] < max_num) {
        ++idx2;
      }
      if (arr3[idx3] < max_num) {
        ++idx3;
      }
    }
    return intersection;
  }
};
