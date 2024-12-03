#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string addSpaces(string s, vector<int>& spaces) {
    string result;
    int space_index = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (space_index < spaces.size() && spaces[space_index] == i) {
        result.push_back(' ');
        ++space_index;
      }
      result.push_back(s[i]);
    }
    return result;
  }
};
