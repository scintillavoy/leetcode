#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> rotated_box(n, vector<char>(m, '.'));
    for (int i = 0; i < m; ++i) {
      int position = n - 1;
      for (int j = n - 1; j >= 0; --j) {
        switch (box[i][j]) {
          case '#':
            rotated_box[position][m - 1 - i] = '#';
            --position;
            break;
          case '*':
            rotated_box[j][m - 1 - i] = '*';
            position = j - 1;
            break;
          case '.':
            break;
        }
      }
    }
    return rotated_box;
  }
};
