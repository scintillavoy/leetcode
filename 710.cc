#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  Solution(int n, vector<int>& blacklist) {
    random_device rd;
    random_engine.seed(rd());
    for (int i = 0; i < blacklist.size(); ++i) {
      mapping[blacklist[i]] = -1;
    }
    total_count = n - mapping.size();
    int next_mapping = n;
    for (int i = 0; i < blacklist.size(); ++i) {
      if (blacklist[i] < total_count) {
        do {
          --next_mapping;
        } while (mapping.count(next_mapping) > 0);
        mapping[blacklist[i]] = next_mapping;
      }
    }
  }

  int pick() {
    int val = random_engine() % total_count;
    if (mapping.count(val) > 0) {
      return mapping[val];
    }
    return val;
  }

 private:
  default_random_engine random_engine;
  unordered_map<int, int> mapping;
  int total_count;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
