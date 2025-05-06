#include <cctype>
#include <cmath>
#include <string>
using namespace std;

class Solution {
 public:
  string reformat(string s) {
    string alphabets;
    string numbers;
    for (const auto c : s) {
      if (isalpha(c)) {
        alphabets += c;
      } else {
        numbers += c;
      }
    }
    string result;
    if (abs((int)alphabets.size() - (int)numbers.size()) >= 2) {
      return "";
    }
    if (alphabets.size() < numbers.size()) {
      result += numbers.back();
      numbers.pop_back();
    }
    while (!numbers.empty()) {
      result += alphabets.back();
      alphabets.pop_back();
      result += numbers.back();
      numbers.pop_back();
    }
    if (!alphabets.empty()) {
      result += alphabets.back();
    }
    return result;
  }
};
