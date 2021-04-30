#include <vector>
#include <utility>
using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res;
    res.push_back(1);
    for (int i = 1; i <= rowIndex; ++i) {
      vector<int> next_row;
      next_row.push_back(1);
      for (int j = 1; j < i; ++j) {
        next_row.push_back(res[j-1] + res[j]);
      }
      next_row.push_back(1);
      res = std::move(next_row);
    }
    return res;
  }
};

int main() { return 0; }
