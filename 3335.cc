#include <deque>
#include <string>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int lengthAfterTransformations(string s, int t) {
    deque<int> counts(26);
    for (const auto c : s) {
      ++counts[c - 'a'];
    }
    for (int i = 0; i < t; ++i) {
      counts.push_front(counts.back());
      counts[1] = (counts[1] + counts.back()) % MOD;
      counts.pop_back();
    }
    int length = 0;
    for (const auto count : counts) {
      length = (length + count) % MOD;
    }
    return length;
  }
};
