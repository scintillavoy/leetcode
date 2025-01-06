#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int left_count = 0;
    int right_count = 0;
    int curr_operations = 0;
    for (int i = 0; i < boxes.size(); ++i) {
      if (boxes[i] == '1') {
        ++right_count;
        curr_operations += i + 1;
      }
    }
    vector<int> min_operations(boxes.size());
    for (int i = 0; i < boxes.size(); ++i) {
      curr_operations += left_count - right_count;
      if (boxes[i] == '1') {
        ++left_count;
        --right_count;
      }
      min_operations[i] = curr_operations;
    }
    return min_operations;
  }
};
