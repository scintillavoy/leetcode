#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool differByOne(vector<string>& dict) {
    for (int i = 0; i < dict.size(); ++i) {
      for (int j = i + 1; j < dict.size(); ++j) {
        int difference = 0;
        for (int k = 0; k < dict[i].size(); ++k) {
          if (dict[i][k] != dict[j][k]) {
            ++difference;
            if (difference > 1) {
              break;
            }
          }
        }
        if (difference == 1) {
          return true;
        }
      }
    }
    return false;
  }
};
