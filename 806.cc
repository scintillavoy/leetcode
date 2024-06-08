#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string s) {
    vector<int> result{1, 0};
    for (const auto c : s) {
      int width = widths[c - 'a'];
      if (width + result[1] <= 100) {
        result[1] += width;
      } else {
        ++result[0];
        result[1] = width;
      }
    }
    return result;
  }
};
