#include <vector>
using namespace std;

class Solution {
 public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    int max_x = find_bound(image, x, image.size() - 1, 0, true) - 1;
    int min_x = find_bound(image, 0, x, 0, false);
    int max_y = find_bound(image, y, image[0].size() - 1, 1, true) - 1;
    int min_y = find_bound(image, 0, y, 1, false);
    return (max_x - min_x + 1) * (max_y - min_y + 1);
  }

 private:
  int find_bound(const vector<vector<char>>& image, int low, int high,
                 int dimension, bool negative) {
    while (low <= high) {
      int mid = low + (high - low) / 2;
      bool found = false;
      if (dimension == 0) {
        for (int i = 0; i < image[0].size(); ++i) {
          if (image[mid][i] == '1') {
            found = true;
            break;
          }
        }
      } else {
        for (int i = 0; i < image.size(); ++i) {
          if (image[i][mid] == '1') {
            found = true;
            break;
          }
        }
      }
      if (found ^ negative) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};
