#include <algorithm>
#include <random>
#include <vector>
using namespace std;

class Solution {
 public:
  Solution(vector<int>& w) {
    random_device rd;
    random_engine.seed(rd());
    prefix_sum = vector<int>(w.size());
    prefix_sum[0] = w[0];
    for (int i = 1; i < w.size(); ++i) {
      prefix_sum[i] = prefix_sum[i - 1] + w[i];
    }
  }

  int pickIndex() {
    int val = random_engine() % prefix_sum.back();
    return upper_bound(prefix_sum.cbegin(), prefix_sum.cend(), val) -
           prefix_sum.cbegin();
  }

 private:
  default_random_engine random_engine;
  vector<int> prefix_sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
