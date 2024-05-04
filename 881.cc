#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    int left = 0, right = people.size() - 1;
    while (left <= right) {
      if (people[left] + people[right] <= limit) {
        ++left;
        --right;
      } else {
        --right;
      }
      ++answer;
    }
    return answer;
  }
};
