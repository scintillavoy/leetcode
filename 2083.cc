#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  long long numberOfSubstrings(string s) {
    vector<int> frequencies(26);
    for (const auto c : s) {
      ++frequencies[c - 'a'];
    }
    long long result = 0;
    for (int i = 0; i < frequencies.size(); ++i) {
      result += (long long)frequencies[i] * (frequencies[i] + 1) / 2;
    }
    return result;
  }
};
