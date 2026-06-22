#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> scoreValidator(vector<string>& events) {
    int score = 0;
    int counter = 0;
    for (const auto& event : events) {
      if (event == "W") {
        ++counter;
        if (counter == 10) {
          break;
        }
      } else if (event == "WD" || event == "NB") {
        ++score;
      } else {
        score += event[0] - '0';
      }
    }
    return {score, counter};
  }
};
