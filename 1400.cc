#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canConstruct(string s, int k) {
    vector<int> counts(26);
    for (const auto c : s) {
      counts[c - 'a'] ^= 1;
    }
    int odd_count = 0;
    for (const auto count : counts) {
      odd_count += count;
    }
    return odd_count <= k && k <= s.size();
  }
};
