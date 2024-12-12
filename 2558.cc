#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int> pq(gifts.begin(), gifts.end());
    while (k > 0) {
      int gift = pq.top();
      pq.pop();
      pq.push(sqrt(gift));
      --k;
    }
    long long sum = 0;
    while (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
    return sum;
  }
};
