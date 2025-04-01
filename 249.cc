#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> sequence_to_strings;
    for (const auto& str : strings) {
      char shift = str[0] - 'a';
      string sequence;
      for (const auto ch : str) {
        sequence.push_back((ch - 'a' - shift + 26) % 26 + 'a');
      }
      sequence_to_strings[sequence].push_back(str);
    }
    vector<vector<string>> result;
    for (auto it = sequence_to_strings.begin(); it != sequence_to_strings.end();
         ++it) {
      result.push_back(it->second);
    }
    return result;
  }
};
