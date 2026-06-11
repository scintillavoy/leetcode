#include <vector>
using namespace std;

class Solution {
 public:
  int maximumPopulation(vector<vector<int>>& logs) {
    vector<int> populations(101);
    for (const auto& log : logs) {
      ++populations[log[0] - 1950];
      --populations[log[1] - 1950];
    }
    int max_population_index = 0;
    for (int i = 1; i < populations.size(); ++i) {
      populations[i] += populations[i - 1];
      if (populations[max_population_index] < populations[i]) {
        max_population_index = i;
      }
    }
    return max_population_index + 1950;
  }
};
