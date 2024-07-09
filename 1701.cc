#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    long long total_waiting_time = 0;
    int last_time = 0;
    for (const auto& customer : customers) {
      total_waiting_time += max(0, last_time - customer[0]) + customer[1];
      last_time = max(last_time, customer[0]) + customer[1];
    }
    return (double)total_waiting_time / customers.size();
  }
};
