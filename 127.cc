#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, int> distances;
    for (const auto& word : wordList) {
      distances[word] = 0;
    }
    distances[beginWord] = 1;
    queue<string> q;
    q.push(beginWord);
    while (!q.empty()) {
      string curr = q.front();
      q.pop();
      for (int i = 0; i < curr.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
          char c = 'a' + j;
          if (curr[i] == c) {
            continue;
          }
          string next = curr;
          next[i] = c;
          if (!distances.contains(next) || distances[next] != 0) {
            continue;
          }
          distances[next] = distances[curr] + 1;
          q.push(next);
        }
      }
    }
    return distances.contains(endWord) ? distances[endWord] : 0;
  }
};
