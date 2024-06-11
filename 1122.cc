#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> frequencies(1001);
    for (const auto x : arr1) {
      ++frequencies[x];
    }
    vector<int> result;
    for (const auto x : arr2) {
      while (frequencies[x] > 0) {
        result.push_back(x);
        --frequencies[x];
      }
    }
    for (int i = 0; i < frequencies.size(); ++i) {
      while (frequencies[i] > 0) {
        result.push_back(i);
        --frequencies[i];
      }
    }
    return result;
  }
};
