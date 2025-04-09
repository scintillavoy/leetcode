#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    unordered_set<string> binary_codes;
    for (int i = 0; i + k - 1 < s.size(); ++i) {
      binary_codes.insert(s.substr(i, k));
    }
    return binary_codes.size() == (1 << k);
  }
};
