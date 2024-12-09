#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int rearrangeCharacters(string s, string target) {
    unordered_map<char, int> counts1, counts2;
    for (const auto c : s) {
      ++counts1[c];
    }
    for (const auto c : target) {
      ++counts2[c];
    }
    int max_num = s.size();
    for (const auto [c, count] : counts2) {
      max_num = min(max_num, counts1[c] / count);
    }
    return max_num;
  }
};
