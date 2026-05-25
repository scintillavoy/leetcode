#include <vector>
using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int low = 0;
    int high = citations.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (citations.size() - mid <= citations[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return citations.size() - low;
  }
};
