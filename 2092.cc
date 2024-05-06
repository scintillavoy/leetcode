#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    sort(
        meetings.begin(), meetings.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });
    parent = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
    rank = vector<int>(n);
    union_set(0, firstPerson);
    int left = 0;
    while (left < meetings.size()) {
      int right = left + 1;
      while (right < meetings.size() &&
             meetings[left][2] == meetings[right][2]) {
        ++right;
      }
      for (int i = left; i < right; ++i) {
        union_set(meetings[i][0], meetings[i][1]);
      }
      for (int i = left; i < right; ++i) {
        if (find_set(meetings[i][0]) != find_set(0)) {
          parent[meetings[i][0]] = meetings[i][0];
          rank[meetings[i][0]] = 0;
        }
        if (find_set(meetings[i][1]) != find_set(0)) {
          parent[meetings[i][1]] = meetings[i][1];
          rank[meetings[i][1]] = 0;
        }
      }
      left = right;
    }
    vector<int> answer;
    for (int i = 0; i < n; ++i) {
      if (find_set(i) == find_set(0)) {
        answer.push_back(i);
      }
    }
    return answer;
  }

 private:
  vector<int> parent;
  vector<int> rank;

  int find_set(int x) {
    if (parent[x] != x) {
      parent[x] = find_set(parent[x]);
    }
    return parent[x];
  }

  void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return;
    }
    if (rank[x] > rank[y]) {
      swap(x, y);
    } else if (rank[x] == rank[y]) {
      ++rank[y];
    }
    parent[x] = y;
  }
};
