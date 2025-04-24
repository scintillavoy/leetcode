#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int buyChoco(vector<int>& prices, int money) {
    priority_queue<int> pq;
    for (const auto price : prices) {
      pq.push(price);
      if (pq.size() > 2) {
        pq.pop();
      }
    }
    int sum = pq.top();
    pq.pop();
    sum += pq.top();
    return money >= sum ? money - sum : money;
  }
};
