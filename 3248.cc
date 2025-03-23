#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int finalPositionOfSnake(int n, vector<string>& commands) {
    int pos = 0;
    for (const auto& command : commands) {
      if (command == "LEFT") {
        --pos;
      } else if (command == "RIGHT") {
        ++pos;
      } else if (command == "UP") {
        pos -= n;
      } else if (command == "DOWN") {
        pos += n;
      }
    }
    return pos;
  }
};
