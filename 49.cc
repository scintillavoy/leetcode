#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (const auto& str : strs) {
      vector<int> count(26);
      for (const auto c : str) {
        ++count[c - 'a'];
      }
      string key;
      for (const auto c : count) {
        key += to_string(c) + ' ';
      }
      m[key].push_back(str);
    }
    vector<vector<string>> result;
    for (const auto& [_, value] : m) {
      result.push_back(value);
    }
    return result;
  }
};
