#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    vector<int> shortest_distances(s.size());
    int curr_distance = s.size();
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == c) {
        curr_distance = 0;
      } else {
        ++curr_distance;
      }
      shortest_distances[i] = curr_distance;
    }
    curr_distance = s.size();
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == c) {
        curr_distance = 0;
      } else {
        ++curr_distance;
      }
      shortest_distances[i] = min(shortest_distances[i], curr_distance);
    }
    return shortest_distances;
  }
};
