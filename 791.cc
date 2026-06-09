#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string customSortString(string order, string s) {
    unordered_map<char, int> char_to_order;
    for (int i = 0; i < order.size(); ++i) {
      char_to_order[order[i]] = i;
    }
    sort(s.begin(), s.end(), [&](const char a, const char b) {
      return char_to_order[a] < char_to_order[b];
    });
    return s;
  }
};
