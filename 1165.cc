#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int calculateTime(string keyboard, string word) {
    unordered_map<char, int> char_to_index;
    for (int i = 0; i < keyboard.size(); ++i) {
      char_to_index[keyboard[i]] = i;
    }
    int current_index = 0;
    int time_to_type = 0;
    for (const auto c : word) {
      time_to_type += abs(current_index - char_to_index[c]);
      current_index = char_to_index[c];
    }
    return time_to_type;
  }
};
