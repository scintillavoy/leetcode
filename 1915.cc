#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    long long answer = 0;
    unordered_map<int, int> freq;
    freq[0] = 1;
    int mask = 0;
    for (int i = 0; i < word.size(); ++i) {
      mask ^= (1 << (word[i] - 'a'));
      answer += freq[mask];
      for (int j = 0; j < 10; ++j) {
        answer += freq[mask ^ (1 << j)];
      }
      ++freq[mask];
    }
    return answer;
  }
};
