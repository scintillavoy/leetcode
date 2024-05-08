#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();
    vector<int> index(n);
    for (int i = 0; i < n; ++i) {
      index[i] = i;
    }
    sort(index.begin(), index.end(),
         [&](int a, int b) { return score[a] > score[b]; });
    vector<string> answer(n);
    for (int i = 0; i < n; ++i) {
      switch (i) {
        case 0:
          answer[index[i]] = "Gold Medal";
          break;
        case 1:
          answer[index[i]] = "Silver Medal";
          break;
        case 2:
          answer[index[i]] = "Bronze Medal";
          break;
        default:
          answer[index[i]] = to_string(i + 1);
      }
    }
    return answer;
  }
};
