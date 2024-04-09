#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int answer = 0;
    for (int i = 0; i < k; ++i) {
      answer += min(tickets[i], tickets[k]);
    }
    answer += tickets[k];
    for (int i = k + 1; i < tickets.size(); ++i) {
      answer += min(tickets[i], tickets[k] - 1);
    }
    return answer;
  }
};
