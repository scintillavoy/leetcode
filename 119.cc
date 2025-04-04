#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> row;
    row.push_back(1);
    for (int i = 1; i <= rowIndex; ++i) {
      vector<int> next_row;
      next_row.push_back(1);
      for (int j = 1; j < i; ++j) {
        next_row.push_back(row[j - 1] + row[j]);
      }
      next_row.push_back(1);
      row = next_row;
    }
    return row;
  }
};
