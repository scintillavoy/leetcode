#include <string>
using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
    char diff = 0;
    for (const auto &c : s) {
      diff ^= c;
    }
    for (const auto &c : t) {
      diff ^= c;
    }
    return diff;
  }
};

int main() { return 0; }
