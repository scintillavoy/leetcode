#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Interval {
 public:
  int start;
  int end;

  Interval() {}

  Interval(int _start, int _end) {
    start = _start;
    end = _end;
  }
};

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
 public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    auto comp = [&](const pair<int, int> &a, const pair<int, int> &b) {
      return schedule[a.first][a.second].start >
             schedule[b.first][b.second].start;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(
        comp);
    for (int i = 0; i < schedule.size(); ++i) {
      pq.push({i, 0});
    }
    int last_end = schedule[pq.top().first][pq.top().second].end;
    vector<Interval> answer;
    while (!pq.empty()) {
      auto [i, j] = pq.top();
      pq.pop();
      Interval curr = schedule[i][j];
      if (curr.start > last_end) {
        answer.emplace_back(last_end, curr.start);
      }
      last_end = max(last_end, curr.end);
      if (schedule[i].size() > j + 1) {
        pq.push({i, j + 1});
      }
    }
    return answer;
  }
};
