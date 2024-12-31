#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> min_costs(days.back() + 1);
    int day_index = 0;
    for (int day = 1; day < min_costs.size(); ++day) {
      if (day < days[day_index]) {
        min_costs[day] = min_costs[day - 1];
      } else {
        ++day_index;
        min_costs[day] = min({min_costs[day - 1] + costs[0],
                              min_costs[max(0, day - 7)] + costs[1],
                              min_costs[max(0, day - 30)] + costs[2]});
      }
    }
    return min_costs.back();
  }
};
