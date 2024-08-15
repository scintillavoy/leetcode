#include <vector>
using namespace std;

class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    int num_of_zeros = 0;
    int insertion = arr.size() - 1;
    for (int i = 0; i < arr.size() - num_of_zeros; ++i) {
      if (arr[i] == 0) {
        if (i == arr.size() - 1 - num_of_zeros) {
          arr[insertion] = 0;
          --insertion;
        }
        ++num_of_zeros;
      }
    }
    for (int i = arr.size() - 1 - num_of_zeros; i >= 0; --i) {
      arr[insertion] = arr[i];
      --insertion;
      if (arr[i] == 0) {
        arr[insertion] = arr[i];
        --insertion;
      }
    }
  }
};
