#include <vector>
using namespace std;

class Solution {
 public:
  bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) {
      return false;
    }
    int i = 1;
    while (i < arr.size() && arr[i - 1] < arr[i]) {
      ++i;
    }
    if (i == arr.size() || arr[i - 1] == arr[i] || i == 1) {
      return false;
    }
    while (i < arr.size() && arr[i - 1] > arr[i]) {
      ++i;
    }
    return i == arr.size();
  }
};
