#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
      return false;
    }
    unordered_map<int, int> frequencies;
    for (const auto card : hand) {
      ++frequencies[card];
    }
    for (auto card : hand) {
      while (frequencies[card - 1] > 0) {
        --card;
      }
      while (frequencies[card] > 0) {
        int frequency = frequencies[card];
        for (int i = card; i < card + groupSize; ++i) {
          if (frequencies[i] < frequency) {
            return false;
          }
          frequencies[i] -= frequency;
        }
        ++card;
      }
    }
    return true;
  }
};
