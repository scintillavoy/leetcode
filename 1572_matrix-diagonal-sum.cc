#include <vector>
using namespace std;

class Solution {
 public:
  int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    for (int i = 0; i < mat.size(); ++i) {
      sum += mat[i][i] + mat[i][mat.size() - i - 1];
    }
    if (mat.size() % 2) {
      sum -= mat[mat.size() / 2][mat.size() / 2];
    }
    return sum;
  }
};

int main() { return 0; }
