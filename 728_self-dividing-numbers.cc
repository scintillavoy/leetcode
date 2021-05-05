#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    for (int i = left; i <= right; ++i) {
      int num;
      for (num = i; num > 0; num /= 10) {
        if (num % 10 == 0 || i % (num % 10) != 0) {
          break;
        }
      }
      if (num == 0) {
        res.push_back(i);
      }
    }
    return res;
  }
};

int main() { return 0; }
