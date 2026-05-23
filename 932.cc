#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> beautifulArray(int n) {
    vector<int> result = {1};
    while (result.size() < n) {
      vector<int> temp;
      for (const auto num : result) {
        if (num * 2 - 1 <= n) {
          temp.push_back(num * 2 - 1);
        }
      }
      for (const auto num : result) {
        if (num * 2 <= n) {
          temp.push_back(num * 2);
        }
      }
      result = temp;
    }
    return result;
  }
};
