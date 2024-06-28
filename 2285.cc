#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution {
 public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> degrees(n);
    for (const auto& road : roads) {
      ++degrees[road[0]];
      ++degrees[road[1]];
    }
    sort(degrees.begin(), degrees.end(), greater<int>());
    long long result = 0;
    for (const auto degree : degrees) {
      result += (long long)degree * n;
      --n;
    }
    return result;
  }
};
