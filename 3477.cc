#include <vector>
using namespace std;

class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int num_of_unplaced_fruits = 0;
    for (const auto fruit : fruits) {
      bool unplaced = true;
      for (int i = 0; i < baskets.size(); ++i) {
        if (fruit <= baskets[i]) {
          baskets[i] = 0;
          unplaced = false;
          break;
        }
      }
      if (unplaced) {
        ++num_of_unplaced_fruits;
      }
    }
    return num_of_unplaced_fruits;
  }
};
