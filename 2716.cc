#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int minimizedStringLength(string s) {
    return unordered_set<char>(s.begin(), s.end()).size();
  }
};
