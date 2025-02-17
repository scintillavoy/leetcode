#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int numTilePossibilities(string tiles) {
    unordered_map<char, int> counts;
    for (const auto c : tiles) {
      ++counts[c];
    }
    return backtrack(counts);
  }

 private:
  int backtrack(unordered_map<char, int> &counts) {
    int possibilities = 0;
    for (auto it = counts.begin(); it != counts.end(); ++it) {
      if (it->second == 0) {
        continue;
      }
      --(it->second);
      ++possibilities;
      possibilities += backtrack(counts);
      ++(it->second);
    }
    return possibilities;
  }
};
