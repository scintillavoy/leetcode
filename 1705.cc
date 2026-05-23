#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;  // (expiry day, num_of_apples) pairs
    int count = 0;
    int day = 0;
    while (day < apples.size() || !pq.empty()) {
      while (!pq.empty() && pq.top().first <= day) {
        pq.pop();
      }
      if (day < apples.size() && apples[day] > 0) {
        pq.push({day + days[day], apples[day]});
      }
      if (!pq.empty()) {
        pair<int, int> t = pq.top();
        pq.pop();
        --t.second;
        if (t.second > 0) {
          pq.push(t);
        }
        ++count;
      }
      ++day;
    }
    return count;
  }
};
