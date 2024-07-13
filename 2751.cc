#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> survivedRobotsHealths(vector<int>& positions,
                                    vector<int>& healths, string directions) {
    int n = positions.size();
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
      indices[i] = i;
    }
    sort(indices.begin(), indices.end(),
         [&](const int a, const int b) { return positions[a] < positions[b]; });

    stack<int> stk;
    for (const auto i : indices) {
      if (directions[i] == 'R') {
        stk.push(i);
      } else {
        while (!stk.empty()) {
          int t = stk.top();
          if (healths[t] > healths[i]) {
            --healths[t];
            healths[i] = 0;
            break;
          } else if (healths[t] < healths[i]) {
            healths[t] = 0;
            stk.pop();
            --healths[i];
          } else {
            healths[t] = 0;
            stk.pop();
            healths[i] = 0;
            break;
          }
        }
      }
    }

    vector<int> result;
    for (const auto health : healths) {
      if (health > 0) {
        result.push_back(health);
      }
    }
    return result;
  }
};
