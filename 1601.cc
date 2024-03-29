#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    int m = requests.size();
    vector<bool> achieved(m);
    int answer = 0;
    for (int i = 1; i <= m; ++i) {
      achieved[m - i] = true;
      do {
        vector<int> count(n);
        for (int j = 0; j < m; ++j) {
          if (achieved[j]) {
            --count[requests[j][0]];
            ++count[requests[j][1]];
          }
        }
        bool valid = true;
        for (int j = 0; j < n; ++j) {
          if (count[j] != 0) {
            valid = false;
            break;
          }
        }
        if (valid) {
          answer = max(answer, i);
        }
      } while (next_permutation(achieved.begin(), achieved.end()));
    }
    return answer;
  }
};
