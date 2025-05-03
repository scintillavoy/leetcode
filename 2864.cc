#include <string>
using namespace std;

class Solution {
 public:
  string maximumOddBinaryNumber(string s) {
    int num_of_ones = 0;
    for (const auto c : s) {
      if (c == '1') {
        ++num_of_ones;
      }
    }
    string result(s.size(), '0');
    for (int i = 0; i < num_of_ones - 1; ++i) {
      result[i] = '1';
    }
    result.back() = '1';
    return result;
  }
};
