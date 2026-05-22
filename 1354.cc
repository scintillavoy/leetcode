#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isPossible(vector<int>& target) {
    int n = target.size();
    long long sum = 0;
    priority_queue<int> pq;
    for (const auto num : target) {
      pq.push(num);
      sum += num;
    }
    while (sum > n) {
      int max_num = pq.top();
      pq.pop();
      if (sum - max_num == 0) {
        return false;
      }
      int new_num = max_num % (sum - max_num);
      if (new_num == 0) {
        new_num += sum - max_num;
      }
      if (new_num == max_num) {
        return false;
      }
      pq.push(new_num);
      sum -= max_num - new_num;
    }
    return sum == n;
  }
};
