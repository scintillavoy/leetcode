#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int, int>> idx;
    for (int i = 0; i < heights.size(); ++i) {
      idx.push_back({heights[i], i});
    }
    sort(idx.begin(), idx.end(), greater<pair<int, int>>());
    vector<string> answer;
    for (int i = 0; i < idx.size(); ++i) {
      answer.push_back(names[idx[i].second]);
    }
    return answer;
  }
};
