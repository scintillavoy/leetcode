#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> decimalRepresentation(int n) {
    string n_str = to_string(n);
    int multiplier = pow(10, n_str.size() - 1);
    vector<int> result;
    for (const auto c : n_str) {
      int digit = c - '0';
      if (digit != 0) {
        result.push_back(digit * multiplier);
      }
      multiplier /= 10;
    }
    return result;
  }
};
