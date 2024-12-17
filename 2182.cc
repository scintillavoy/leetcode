#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    unordered_map<char, int> counts;
    for (const auto c : s) {
      ++counts[c];
    }
    string result;
    for (char c = 'z'; c >= 'a'; --c) {
      int consecutive_count = 0;
      while (counts[c] > 0) {
        if (consecutive_count == repeatLimit) {
          for (char c2 = c - 1; c2 >= 'a'; --c2) {
            if (counts[c2] > 0) {
              result += c2;
              --counts[c2];
              consecutive_count = 0;
              break;
            }
          }
          if (consecutive_count != 0) {
            return result;
          }
        }
        result += c;
        --counts[c];
        ++consecutive_count;
      }
    }
    return result;
  }
};
