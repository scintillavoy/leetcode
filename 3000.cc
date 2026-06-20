#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int max_diagonal_length = 0;
    int max_area = 0;
    for (const auto& dimension : dimensions) {
      int diagonal_length =
          dimension[0] * dimension[0] + dimension[1] * dimension[1];
      if (max_diagonal_length < diagonal_length) {
        max_diagonal_length = diagonal_length;
        max_area = dimension[0] * dimension[1];
      } else if (max_diagonal_length == diagonal_length) {
        max_area = max(max_area, dimension[0] * dimension[1]);
      }
    }
    return max_area;
  }
};
