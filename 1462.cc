#include <bitset>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<vector<int>> graph(numCourses);
    vector<int> in_degrees(numCourses);
    for (const auto prerequisite : prerequisites) {
      graph[prerequisite[0]].push_back(prerequisite[1]);
      ++in_degrees[prerequisite[1]];
    }
    queue<int> q;
    for (int i = 0; i < in_degrees.size(); ++i) {
      if (in_degrees[i] == 0) {
        q.push(i);
      }
    }
    vector<bitset<128>> full_prerequisites(numCourses);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (const auto adj : graph[curr]) {
        full_prerequisites[adj] |= full_prerequisites[curr];
        full_prerequisites[adj][curr] = true;
        --in_degrees[adj];
        if (in_degrees[adj] == 0) {
          q.push(adj);
        }
      }
    }
    vector<bool> result(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      result[i] = full_prerequisites[queries[i][1]][queries[i][0]];
    }
    return result;
  }
};
