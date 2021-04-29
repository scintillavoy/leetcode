#include <deque>
using namespace std;

class Solution {
 public:
  int tribonacci(int n) {
    deque<int> memo{0, 1, 1};
    if (n <= 2) {
      return memo[n];
    }
    n -= 2;
    while (n > 0) {
      memo.push_back(memo[0] + memo[1] + memo[2]);
      memo.pop_front();
      --n;
    }
    return memo.back();
  }
};

int main() { return 0; }
