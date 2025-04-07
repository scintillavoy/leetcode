#include <cmath>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    vector<vector<int>> num_of_routes(fuel + 1, vector<int>(locations.size()));
    num_of_routes[fuel][start] = 1;
    for (int i = fuel; i >= 0; --i) {
      for (int j = 0; j < locations.size(); ++j) {
        if (num_of_routes[i][j] == 0) {
          continue;
        }
        for (int k = 0; k < locations.size(); ++k) {
          if (j == k) {
            continue;
          }
          int distance = abs(locations[j] - locations[k]);
          if (i - distance < 0) {
            continue;
          }
          num_of_routes[i - distance][k] =
              (num_of_routes[i - distance][k] + num_of_routes[i][j]) % MOD;
        }
      }
    }
    int total_num_of_routes = 0;
    for (int i = 0; i <= fuel; ++i) {
      total_num_of_routes =
          (total_num_of_routes + num_of_routes[i][finish]) % MOD;
    }
    return total_num_of_routes;
  }
};
