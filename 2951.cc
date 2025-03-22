#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findPeaks(vector<int>& mountain) {
    vector<int> peaks;
    for (int i = 1; i + 1 < mountain.size(); ++i) {
      if (mountain[i - 1] < mountain[i] && mountain[i] > mountain[i + 1]) {
        peaks.push_back(i);
      }
    }
    return peaks;
  }
};
