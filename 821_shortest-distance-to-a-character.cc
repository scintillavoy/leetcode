#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// Better solution: two pass
// 1st from left to right
// 2nd from right to left
// take the minimum of two
class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    vector<int> distance(s.size(), s.size());
    int curr_dist = s.size();
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == c) {
        curr_dist = 0;
        for (int j = i; j >= 0 && distance[j] >= curr_dist; --j) {
          distance[j] = curr_dist;
          ++curr_dist;
        }
        curr_dist = 1;
      } else {
        distance[i] = curr_dist;
        ++curr_dist;
      }
    }
    return distance;
  }
};

int main() { return 0; }
