#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    parents = vector<int>(26);
    for (int i = 0; i < parents.size(); ++i) {
      parents[i] = i;
    }
    for (int i = 0; i < s1.size(); ++i) {
      union_set(s1[i] - 'a', s2[i] - 'a');
    }
    string result;
    for (const auto c : baseStr) {
      result.push_back(find_set(c - 'a') + 'a');
    }
    return result;
  }

 private:
  vector<int> parents;

  int find_set(int x) {
    if (parents[x] != x) {
      parents[x] = find_set(parents[x]);
    }
    return parents[x];
  }

  void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return;
    }
    if (x < y) {
      swap(x, y);
    }
    parents[x] = y;
  }
};
