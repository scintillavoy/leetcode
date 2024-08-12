#include <functional>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
 public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for (const auto num : nums) {
      pq.push(num);
    }
    while (pq.size() > k) {
      pq.pop();
    }
  }

  int add(int val) {
    pq.push(val);
    while (pq.size() > k) {
      pq.pop();
    }
    return pq.top();
  }

 private:
  int k;
  priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
