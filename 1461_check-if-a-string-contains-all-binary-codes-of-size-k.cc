#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    unordered_set<string> check;
    int count = 1 << k;
    for (int i = 0; i + k <= s.size(); ++i) {
      // Hashing can be improved by using rolling hash and
      // the fact that s is a binary string
      if (check.insert(s.substr(i, k)).second) {
        --count;
        if (count == 0) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() { return 0; }
