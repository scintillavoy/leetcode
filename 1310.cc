#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> prefix_xor(arr.size() + 1);
    for (int i = 0; i < arr.size(); ++i) {
      prefix_xor[i + 1] = prefix_xor[i] ^ arr[i];
    }
    vector<int> result;
    for (const auto& query : queries) {
      result.push_back(prefix_xor[query[0]] ^ prefix_xor[query[1] + 1]);
    }
    return result;
  }
};
