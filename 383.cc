#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> counts;
    for (const auto &c : magazine) {
      ++counts[c];
    }
    for (const auto &c : ransomNote) {
      if (counts[c] <= 0) {
        return false;
      }
      --counts[c];
    }
    return true;
  }
};
