#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    vector<int> in_degrees(n);
    for (int i = 0; i < n; ++i) {
      ++in_degrees[favorite[i]];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (in_degrees[i] == 0) {
        q.push(i);
      }
    }
    vector<int> depths(n);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      int next = favorite[curr];
      depths[next] = max(depths[next], depths[curr] + 1);
      --in_degrees[next];
      if (in_degrees[next] == 0) {
        q.push(next);
      }
    }
    int max_cycle_length = 0;
    int cycles_with_length_two = 0;
    for (int i = 0; i < n; ++i) {
      if (in_degrees[i] == 0) {
        continue;
      }
      int cycle_length = 0;
      int curr = i;
      while (in_degrees[curr] != 0) {
        in_degrees[curr] = 0;
        ++cycle_length;
        curr = favorite[curr];
      }
      if (cycle_length == 2) {
        cycles_with_length_two += depths[i] + depths[favorite[i]] + 2;
      } else {
        max_cycle_length = max(max_cycle_length, cycle_length);
      }
    }
    return max(max_cycle_length, cycles_with_length_two);
  }
};
