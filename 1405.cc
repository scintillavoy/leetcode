#include <queue>
#include <string>
#include <utility>
using namespace std;

class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>> pq;
    if (a != 0) {
      pq.push({a, 'a'});
    }
    if (b != 0) {
      pq.push({b, 'b'});
    }
    if (c != 0) {
      pq.push({c, 'c'});
    }
    string pattern;
    pair<int, char> prev = {0, 0};
    while (!pq.empty()) {
      pair<int, char> curr = pq.top();
      pq.pop();
      pattern.push_back(curr.second);
      --curr.first;
      if (prev.first > 0) {
        pq.push(prev);
      }
      prev = curr;
    }
    string result;
    for (const auto c : pattern) {
      result.push_back(c);
      if (prev.first > 0 && prev.second == c) {
        --prev.first;
        result.push_back(c);
      }
    }
    return result;
  }
};
