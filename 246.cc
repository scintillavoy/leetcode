#include <string>
using namespace std;

class Solution {
 public:
  bool isStrobogrammatic(string num) {
    int n = num.size();
    for (int i = 0; i <= n / 2; ++i) {
      switch (num[i]) {
        case '2':
        case '3':
        case '4':
        case '5':
        case '7':
          return false;
        case '0':
        case '1':
        case '8':
          if (num[n - 1 - i] != num[i]) {
            return false;
          }
          break;
        case '6':
          if (num[n - 1 - i] != '9') {
            return false;
          }
          break;
        case '9':
          if (num[n - 1 - i] != '6') {
            return false;
          }
          break;
      }
    }
    return true;
  }
};
