#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> counts;
    for (const auto ch : s) {
      ++counts[ch];
    }
    for (const auto ch : t) {
      --counts[ch];
    }
    for (const auto [_, count] : counts) {
      if (count != 0) {
        return false;
      }
    }
    return true;
  }
};
