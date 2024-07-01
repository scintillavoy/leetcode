#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    string result;
    for (const auto c : s) {
      if (c != ']') {
        result += c;
        continue;
      }
      string token;
      while (result.back() != '[') {
        token += result.back();
        result.pop_back();
      }
      reverse(token.begin(), token.end());
      result.pop_back();
      int repetition = 0;
      for (int i = 0; !result.empty() && isdigit(result.back()); ++i) {
        repetition += pow(10, i) * (result.back() - '0');
        result.pop_back();
      }
      for (int i = 0; i < repetition; ++i) {
        result += token;
      }
    }
    return result;
  }
};
