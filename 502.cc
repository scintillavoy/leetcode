#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; ++i) {
      projects[i] = {capital[i], profits[i]};
    }
    sort(projects.begin(), projects.end(), greater<pair<int, int>>());
    priority_queue<int> available_profits;
    for (int i = 0; i < k; ++i) {
      while (!projects.empty() && projects.back().first <= w) {
        available_profits.push(projects.back().second);
        projects.pop_back();
      }
      if (available_profits.empty()) {
        break;
      }
      w += available_profits.top();
      available_profits.pop();
    }
    return w;
  }
};
