#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string getHint(string secret, string guess) {
    unordered_map<char, int> counts;
    for (const auto ch : secret) {
      ++counts[ch];
    }
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < guess.size(); ++i) {
      if (guess[i] == secret[i]) {
        --counts[guess[i]];
        ++bulls;
      }
    }
    for (int i = 0; i < guess.size(); ++i) {
      if (guess[i] != secret[i] && counts[guess[i]] > 0) {
        --counts[guess[i]];
        ++cows;
      }
    }
    return to_string(bulls) + 'A' + to_string(cows) + 'B';
  }
};
