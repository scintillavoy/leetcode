#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  string reorganizeString(string s) {
    vector<int> counts(26);
    for (const auto c : s) {
      ++counts[c - 'a'];
    }
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < counts.size(); ++i) {
      if (counts[i] > 0) {
        pq.push({counts[i], i + 'a'});
      }
    }
    string result;
    while (!pq.empty()) {
      auto [count, ch] = pq.top();
      pq.pop();
      if (result.empty() || ch != result.back()) {
        result += ch;
        if (count >= 2) {
          pq.push({count - 1, ch});
        }
      } else {
        if (pq.empty()) {
          return "";
        }
        auto [count2, ch2] = pq.top();
        pq.pop();
        result += ch2;
        if (count2 >= 2) {
          pq.push({count2 - 1, ch2});
        }
        pq.push({count, ch});
      }
    }
    return result;
  }
};
