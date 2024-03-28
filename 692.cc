#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> frequency;
    for (const auto& word : words) {
      ++frequency[word];
    }
    auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
      if (a.first != b.first) {
        return a.first > b.first;
      }
      return a.second < b.second;
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)>
        pq;
    for (const auto& f : frequency) {
      pq.push({f.second, f.first});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<string> answer;
    while (!pq.empty()) {
      answer.push_back(pq.top().second);
      pq.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
