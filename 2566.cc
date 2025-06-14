#include <string>
using namespace std;

class Solution {
 public:
  int minMaxDifference(int num) {
    string num_str = to_string(num);

    string min_num_str = num_str;
    char remapped_digit = min_num_str.front();
    for (int i = 0; i < min_num_str.size(); ++i) {
      if (min_num_str[i] == remapped_digit) {
        min_num_str[i] = '0';
      }
    }
    int min_num = stoi(min_num_str);

    string max_num_str = num_str;
    remapped_digit = max_num_str.front();
    for (int i = 0; i < max_num_str.size(); ++i) {
      if (max_num_str[i] != '9') {
        remapped_digit = max_num_str[i];
        break;
      }
    }
    for (int i = 0; i < max_num_str.size(); ++i) {
      if (max_num_str[i] == remapped_digit) {
        max_num_str[i] = '9';
      }
    }
    int max_num = stoi(max_num_str);

    return max_num - min_num;
  }
};
