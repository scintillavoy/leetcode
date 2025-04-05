#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkDistances(string s, vector<int>& distance) {
    vector<int> first_occurrences(26, -1);
    for (int i = 0; i < s.size(); ++i) {
      char ch = s[i] - 'a';
      if (first_occurrences[ch] != -1) {
        if (i - first_occurrences[ch] != distance[ch] + 1) {
          return false;
        }
      } else {
        first_occurrences[ch] = i;
      }
    }
    return true;
  }
};
