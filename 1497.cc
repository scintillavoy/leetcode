#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> remainder_counts;
    for (const auto num : arr) {
      int remainder = num % k;
      if (remainder < 0) {
        remainder += k;
      }
      int counterpart = (k - remainder) % k;
      if (remainder_counts.contains(counterpart) &&
          remainder_counts[counterpart] > 0) {
        --remainder_counts[counterpart];
        if (remainder_counts[counterpart] == 0) {
          remainder_counts.erase(counterpart);
        }
      } else {
        ++remainder_counts[remainder];
      }
    }
    return remainder_counts.empty();
  }
};
