#include <string>
#include <utility>
using namespace std;

class Solution {
 public:
  int maximumSwap(int num) {
    string num_str = to_string(num);
    int max_digit_index = -1;
    pair<int, int> swap_index = {-1, -1};
    for (int i = num_str.size() - 1; i >= 0; --i) {
      if (max_digit_index == -1 || num_str[i] > num_str[max_digit_index]) {
        max_digit_index = i;
      } else if (num_str[i] < num_str[max_digit_index]) {
        swap_index = {i, max_digit_index};
      }
    }
    if (swap_index != make_pair(-1, -1)) {
      swap(num_str[swap_index.first], num_str[swap_index.second]);
    }
    return stoi(num_str);
  }
};
