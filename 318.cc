#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    int max_product = 0;
    unordered_map<int, int> mask_to_length;
    for (const auto& word : words) {
      int curr_mask = 0;
      for (const auto c : word) {
        curr_mask |= 1 << (c - 'a');
      }
      for (const auto [mask, length] : mask_to_length) {
        if ((mask & curr_mask) == 0) {
          max_product = max(max_product, length * (int)word.size());
        }
      }
      mask_to_length[curr_mask] =
          max(mask_to_length[curr_mask], (int)word.size());
    }
    return max_product;
  }
};
