#include <queue>
using namespace std;

class Solution {
 public:
  int magicalString(int n) {
    int num_of_ones = 1;
    queue<int> q;
    q.push(2);
    n -= 3;
    while (n > 0) {
      int last = q.back();
      for (int i = 0; i < q.front(); ++i) {
        if (last == 1) {
          q.push(2);
        } else {
          q.push(1);
          ++num_of_ones;
        }
        --n;
        if (n == 0) {
          break;
        }
      }
      q.pop();
    }
    return num_of_ones;
  }
};
