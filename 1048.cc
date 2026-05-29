#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    vector<vector<int>> graph(words.size());
    vector<int> in_degrees(words.size());
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words.size(); ++j) {
        if (i == j || words[i].size() + 1 != words[j].size()) {
          continue;
        }
        int num_of_insertion = 0;
        int k = 0;
        int l = 0;
        while (k < words[i].size() && l < words[j].size()) {
          if (words[i][k] == words[j][l]) {
            ++k;
            ++l;
            continue;
          }
          ++num_of_insertion;
          if (num_of_insertion > 1) {
            break;
          }
          ++l;
        }
        if (num_of_insertion <= 1) {
          graph[i].push_back(j);
          ++in_degrees[j];
        }
      }
    }

    queue<int> q;
    for (int i = 0; i < in_degrees.size(); ++i) {
      if (in_degrees[i] == 0) {
        q.push(i);
      }
    }
    int max_length = 0;
    while (!q.empty()) {
      ++max_length;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        int curr = q.front();
        q.pop();
        for (const auto adj : graph[curr]) {
          --in_degrees[adj];
          if (in_degrees[adj] == 0) {
            q.push(adj);
          }
        }
      }
    }
    return max_length;
  }
};
