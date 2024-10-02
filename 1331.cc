#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    map<int, int> ranks;
    for (const auto num : arr) {
      ranks[num] = 0;
    }
    int rank = 1;
    for (auto it = ranks.begin(); it != ranks.end(); ++it) {
      it->second = rank;
      ++rank;
    }
    vector<int> result(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
      result[i] = ranks[arr[i]];
    }
    return result;
  }
};
