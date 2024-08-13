#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSwapsCouples(vector<int>& row) {
    unordered_map<int, int> id_to_index;
    for (int i = 0; i < row.size(); ++i) {
      id_to_index[row[i]] = i;
    }
    int swaps = 0;
    for (int i = 0; i < row.size(); i += 2) {
      int partner_id = row[i] ^ 1;
      if (row[i + 1] == partner_id) {
        continue;
      }
      int partner_index = id_to_index[partner_id];
      id_to_index[partner_id] = i + 1;
      id_to_index[row[i + 1]] = partner_index;
      swap(row[i + 1], row[partner_index]);
      ++swaps;
    }
    return swaps;
  }
};
