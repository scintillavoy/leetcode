#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    vector<int> last_occurrences(26);
    for (int i = 0; i < s.size(); ++i) {
      last_occurrences[s[i] - 'a'] = i;
    }
    vector<int> result;
    int last_partitioned_index = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (last_partitioned_index < i) {
        result.push_back(1);
      } else {
        ++result.back();
      }
      last_partitioned_index =
          max(last_partitioned_index, last_occurrences[s[i] - 'a']);
    }
    return result;
  }
};
