#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int> blocked_segments;
    for (const auto& seat : reservedSeats) {
      int row = seat[0] - 1;
      int column = seat[1];
      if (2 <= column && column <= 5) {
        blocked_segments[row] |= 1;
      }
      if (4 <= column && column <= 7) {
        blocked_segments[row] |= (1 << 1);
      }
      if (6 <= column && column <= 9) {
        blocked_segments[row] |= (1 << 2);
      }
    }
    int max_allocations = n * 2;
    for (const auto& [_, state] : blocked_segments) {
      switch (state) {
        case 0b111:
          max_allocations -= 2;
          break;
        case 0b000:
          break;
        default:
          --max_allocations;
      }
    }
    return max_allocations;
  }
};
