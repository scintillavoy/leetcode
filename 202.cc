#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> s;
    while (s.count(n) == 0) {
      s.insert(n);
      int next = 0;
      while (n != 0) {
        next += (n % 10) * (n % 10);
        n /= 10;
      }
      n = next;
    }
    return s.count(1) != 0;
  }
};
