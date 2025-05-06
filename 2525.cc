#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  string categorizeBox(int length, int width, int height, int mass) {
    int category = 0;
    if (max({length, width, height}) >= 10'000 ||
        (long long)length * width * height >= 1'000'000'000) {
      category |= 1;
    }
    if (mass >= 100) {
      category |= 1 << 1;
    }
    switch (category) {
      case 1:
        return "Bulky";
      case 2:
        return "Heavy";
      case 3:
        return "Both";
    }
    return "Neither";
  }
};
