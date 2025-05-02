#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();
    vector<int> forces(n);
    int force = 0;
    for (int i = 0; i < n; ++i) {
      if (dominoes[i] == 'R') {
        force = n;
      } else if (dominoes[i] == 'L') {
        force = 0;
      } else {
        force = max(force - 1, 0);
      }
      forces[i] += force;
    }
    force = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (dominoes[i] == 'L') {
        force = n;
      } else if (dominoes[i] == 'R') {
        force = 0;
      } else {
        force = max(force - 1, 0);
      }
      forces[i] -= force;
    }
    string result;
    for (const auto force : forces) {
      if (force > 0) {
        result += 'R';
      } else if (force < 0) {
        result += 'L';
      } else {
        result += '.';
      }
    }
    return result;
  }
};
