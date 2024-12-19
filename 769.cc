#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int num_of_chunks = 0;
    unordered_map<int, int> counts;
    for (int i = 0; i < arr.size(); ++i) {
      ++counts[i];
      if (counts[i] == 0) {
        counts.erase(i);
      }
      --counts[arr[i]];
      if (counts[arr[i]] == 0) {
        counts.erase(arr[i]);
      }
      if (counts.size() == 0) {
        ++num_of_chunks;
      }
    }
    return num_of_chunks;
  }
};
