#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    return can_cut_at_least_twice(rectangles, 0, 2) ||
           can_cut_at_least_twice(rectangles, 1, 3);
  }

 private:
  bool can_cut_at_least_twice(vector<vector<int>>& rectangles, int start_index,
                              int end_index) {
    sort(rectangles.begin(), rectangles.end(),
         [&](const vector<int>& a, const vector<int>& b) {
           if (a[start_index] != b[start_index]) {
             return a[start_index] < b[start_index];
           }
           return a[end_index] < b[end_index];
         });
    int num_of_cuts = 0;
    int last_coordinate = rectangles[0][end_index];
    for (int i = 1; i < rectangles.size(); ++i) {
      if (rectangles[i][start_index] >= last_coordinate) {
        ++num_of_cuts;
        if (num_of_cuts >= 2) {
          return true;
        }
      }
      last_coordinate = max(last_coordinate, rectangles[i][end_index]);
    }
    return false;
  }
};
