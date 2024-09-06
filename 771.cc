#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> jewel_set;
    for (const auto jewel : jewels) {
      jewel_set.insert(jewel);
    }
    int count = 0;
    for (const auto stone : stones) {
      if (jewel_set.contains(stone)) {
        ++count;
      }
    }
    return count;
  }
};
