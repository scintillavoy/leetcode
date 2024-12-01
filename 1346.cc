#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    unordered_set<int> occurrences;
    for (const auto num : arr) {
      if (occurrences.contains(num * 2) ||
          (num % 2 == 0 && occurrences.contains(num / 2))) {
        return true;
      }
      occurrences.insert(num);
    }
    return false;
  }
};
