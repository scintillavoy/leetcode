#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int findPermutationDifference(string s, string t) {
    vector<int> indices(26);
    for (int i = 0; i < s.size(); ++i) {
      indices[s[i] - 'a'] = i;
    }
    int result = 0;
    for (int i = 0; i < t.size(); ++i) {
      result += abs(indices[t[i] - 'a'] - i);
    }
    return result;
  }
};
