#include <string>
using namespace std;

class Solution {
 public:
  bool checkTwoChessboards(string coordinate1, string coordinate2) {
    return (coordinate1[0] - 'a' + coordinate1[1] - '0') % 2 ==
           (coordinate2[0] - 'a' + coordinate2[1] - '0') % 2;
  }
};
