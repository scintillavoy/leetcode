#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> result;
    int start = 0;
    while (start + k - 1 < s.size()) {
      result.push_back(s.substr(start, k));
      start += k;
    }
    if (start < s.size()) {
      result.push_back(s.substr(start));
      while (result.back().size() < k) {
        result.back().push_back(fill);
      }
    }
    return result;
  }
};
