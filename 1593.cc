#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int maxUniqueSplit(string s) {
    unordered_map<string, int> counts;
    return find_max(s, counts, 0);
  }

 private:
  int find_max(const string &s, unordered_map<string, int> &counts, int start) {
    int result = counts.size();
    string curr;
    for (int i = start; i < s.size(); ++i) {
      curr += s[i];
      ++counts[curr];
      result = max(result, find_max(s, counts, i + 1));
      --counts[curr];
      if (counts[curr] == 0) {
        counts.erase(curr);
      }
    }
    return result;
  }
};
