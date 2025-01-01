#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string stringShift(string s, vector<vector<int>>& shift) {
    int total_shift = 0;
    for (const auto& s : shift) {
      total_shift += s[0] == 0 ? s[1] : -s[1];
    }
    string shifted_s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      shifted_s.push_back(s[(i + total_shift % n + n) % n]);
    }
    return shifted_s;
  }
};
