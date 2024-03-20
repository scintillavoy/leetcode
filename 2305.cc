#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int distributeCookies(vector<int>& cookies, int k) {
    this->k = k;
    this->dist = vector<int>(k);
    return backtrack(cookies, 0);
  }

 private:
  int k;
  vector<int> dist;

  int backtrack(vector<int>& cookies, int index) {
    if (index == cookies.size()) {
      int max_count = 0;
      for (int i = 0; i < dist.size(); ++i) {
        max_count = max(max_count, dist[i]);
      }
      return max_count;
    }

    int answer = numeric_limits<int>::max();
    for (int i = 0; i < k; ++i) {
      dist[i] += cookies[index];
      answer = min(answer, backtrack(cookies, index + 1));
      dist[i] -= cookies[index];
    }
    return answer;
  }
};
