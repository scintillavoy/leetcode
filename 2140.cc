#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> max_points(n);
    max_points[n - 1] = questions[n - 1][0];
    for (int i = n - 2; i >= 0; --i) {
      long long points = questions[i][0];
      int brainpower = questions[i][1];
      int next_index_when_solved = i + brainpower + 1;
      if (next_index_when_solved < n) {
        points += max_points[next_index_when_solved];
      }
      max_points[i] = max(max_points[i + 1], points);
    }
    return max_points.front();
  }
};
