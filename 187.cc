#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> counts;
    for (int i = 0; i + 9 < s.size(); ++i) {
      ++counts[s.substr(i, 10)];
    }
    vector<string> repeated;
    for (const auto [sub, count] : counts) {
      if (count > 1) {
        repeated.push_back(sub);
      }
    }
    return repeated;
  }
};
