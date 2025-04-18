#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int captureForts(vector<int>& forts) {
    int max_captures = 0;
    int start = -1;
    for (int end = 0; end < forts.size(); ++end) {
      if (forts[end] == 0) {
        continue;
      }
      if (start != -1 && forts[start] + forts[end] == 0) {
        max_captures = max(max_captures, end - start - 1);
      }
      start = end;
    }
    return max_captures;
  }
};
