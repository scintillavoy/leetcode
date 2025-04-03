#include <string>
using namespace std;

class Solution {
 public:
  string getHappyString(int n, int k) {
    if (3 << (n - 1) < k) {
      return "";
    }
    string happy_string;
    for (int i = 1 << (n - 1); i > 0; i >>= 1) {
      for (int j = 0; j < 3; ++j) {
        char next_char = 'a' + j;
        if (!happy_string.empty() && happy_string.back() == next_char) {
          continue;
        }
        if (i >= k) {
          happy_string.push_back(next_char);
          break;
        }
        k -= i;
      }
    }
    return happy_string;
  }
};
