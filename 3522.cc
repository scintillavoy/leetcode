#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  long long calculateScore(vector<string>& instructions, vector<int>& values) {
    long long score = 0;
    int i = 0;
    vector<bool> visited(instructions.size());
    while (0 <= i && i < instructions.size()) {
      if (visited[i]) {
        break;
      }
      visited[i] = true;
      if (instructions[i] == "add") {
        score += values[i];
        ++i;
      } else {
        i += values[i];
      }
    }
    return score;
  }
};
