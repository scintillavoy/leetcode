#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int scheduleCourse(vector<vector<int>> &courses) {
    sort(courses.begin(), courses.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
    int time = 0;
    priority_queue<int> max_heap;
    for (int i = 0; i < courses.size(); ++i) {
      if (time + courses[i][0] <= courses[i][1]) {
        time += courses[i][0];
        max_heap.push(courses[i][0]);
      } else if (!max_heap.empty() && max_heap.top() > courses[i][0]) {
        time += courses[i][0] - max_heap.top();
        max_heap.pop();
        max_heap.push(courses[i][0]);
      }
    }
    return max_heap.size();
  }
};

int main() { return 0; }
