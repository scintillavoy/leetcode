#include <algorithm>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  int visibleMountains(vector<vector<int>>& peaks) {
    sort(peaks.begin(), peaks.end());
    stack<tuple<int, int, bool>> stk;
    for (int i = 0; i < peaks.size(); ++i) {
      int x1 = peaks[i][0], y1 = peaks[i][1];
      bool should_push = true;
      while (!stk.empty()) {
        auto [x2, y2, _] = stk.top();
        if (x1 == x2) {
          if (y1 == y2) {
            get<2>(stk.top()) = false;
            should_push = false;
            break;
          } else {
            stk.pop();
            continue;
          }
        }
        double gradient = (double)(y1 - y2) / (x1 - x2);
        if (gradient >= 1) {
          stk.pop();
        } else if (gradient <= -1) {
          should_push = false;
          break;
        } else {
          break;
        }
      }
      if (should_push) {
        stk.push({x1, y1, true});
      }
    }
    int answer = 0;
    while (!stk.empty()) {
      if (get<2>(stk.top())) {
        ++answer;
      }
      stk.pop();
    }
    return answer;
  }
};
