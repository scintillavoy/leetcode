#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int findTheLongestSubstring(string s) {
    unordered_map<int, int> mask_to_index;
    mask_to_index[0] = 0;
    int running_mask = 0;
    int max_length = 0;
    for (int i = 0; i < s.size(); ++i) {
      int mask = 1;
      switch (s[i]) {
        case 'a':
          mask <<= 1;
        case 'e':
          mask <<= 1;
        case 'i':
          mask <<= 1;
        case 'o':
          mask <<= 1;
        case 'u':
          running_mask ^= mask;
          break;
        default:
          break;
      }
      if (mask_to_index.contains(running_mask)) {
        max_length = max(max_length, i - mask_to_index[running_mask] + 1);
      } else {
        mask_to_index[running_mask] = i + 1;
      }
    }
    return max_length;
  }
};
