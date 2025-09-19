#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> positions;
    int start = 0, end = 1;
    while (end <= s.size()) {
      if (end == s.size() || s[start] != s[end]) {
        if (end - start >= 3) {
          positions.push_back({start, end - 1});
        }
        start = end;
      }
      ++end;
    }
    return positions;
  }
};
