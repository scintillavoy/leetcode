#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_map<string, int> distances;
    for (const auto& gene : bank) {
      distances[gene] = -1;
    }
    distances[startGene] = 0;
    queue<string> q;
    q.push(startGene);
    while (!q.empty()) {
      string curr = q.front();
      q.pop();
      for (int i = 0; i < curr.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
          if (curr[i] == chars[j]) {
            continue;
          }
          string next = curr;
          next[i] = chars[j];
          if (!distances.contains(next) || distances[next] != -1) {
            continue;
          }
          distances[next] = distances[curr] + 1;
          q.push(next);
        }
      }
    }
    return distances.contains(endGene) ? distances[endGene] : -1;
  }

 private:
  const char chars[4] = {'A', 'C', 'G', 'T'};
};
