#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    int n = wordsDict.size();
    int shortest_distance = n;
    int index1 = -n;
    int index2 = -n;
    for (int i = 0; i < n; ++i) {
      if (wordsDict[i] == word1) {
        index1 = i;
        shortest_distance = min(shortest_distance, index1 - index2);
      } else if (wordsDict[i] == word2) {
        index2 = i;
        shortest_distance = min(shortest_distance, index2 - index1);
      }
    }
    return shortest_distance;
  }
};
