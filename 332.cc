#include <algorithm>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, multiset<string>> adjacencies;
    for (const auto& ticket : tickets) {
      adjacencies[ticket[0]].insert(ticket[1]);
    }
    vector<string> result;
    stack<string> s;
    s.push("JFK");
    while (!s.empty()) {
      string curr = s.top();
      if (adjacencies[curr].empty()) {
        result.push_back(curr);
        s.pop();
      } else {
        string next = *adjacencies[curr].begin();
        adjacencies[curr].extract(next);
        s.push(next);
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
