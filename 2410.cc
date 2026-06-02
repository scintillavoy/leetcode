#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    int players_index = 0;
    int trainers_index = 0;
    while (players_index < players.size() && trainers_index < trainers.size()) {
      if (players[players_index] <= trainers[trainers_index]) {
        ++players_index;
      }
      ++trainers_index;
    }
    return players_index;
  }
};
