#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int left = 0, right = costs.size() - 1;
    auto comp = [](const Worker &a, const Worker &b) {
      if (a.cost != b.cost) {
        return a.cost > b.cost;
      }
      return a.index > b.index;
    };
    priority_queue<Worker, vector<Worker>, decltype(comp)> pq;
    for (int i = 0; i < candidates; ++i) {
      pq.push({costs[left], left, true});
      ++left;
      if (left > right) {
        break;
      }
      pq.push({costs[right], right, false});
      --right;
      if (left > right) {
        break;
      }
    }
    long long total_cost = 0;
    while (k > 0) {
      Worker worker = pq.top();
      pq.pop();
      total_cost += worker.cost;
      if (left <= right) {
        if (worker.is_from_left) {
          pq.push({costs[left], left, true});
          ++left;
        } else {
          pq.push({costs[right], right, false});
          --right;
        }
      }
      --k;
    }
    return total_cost;
  }

 private:
  struct Worker {
    int cost;
    int index;
    bool is_from_left;
  };
};
