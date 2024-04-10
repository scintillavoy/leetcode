#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    sort(deck.begin(), deck.end());
    deque<int> indexes(n);
    for (int i = 0; i < n; ++i) {
      indexes[i] = i;
    }
    vector<int> answer(n);
    for (int i = 0; i < n; ++i) {
      answer[indexes.front()] = deck[i];
      indexes.pop_front();
      if (!indexes.empty()) {
        indexes.push_back(indexes.front());
        indexes.pop_front();
      }
    }
    return answer;
  }
};
