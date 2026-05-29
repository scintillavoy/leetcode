#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> str_to_index;
    for (int i = 0; i < list1.size(); ++i) {
      str_to_index[list1[i]] = i;
    }
    int least_index_sum = list1.size() + list2.size();
    vector<string> common_strings;
    for (int i = 0; i < list2.size(); ++i) {
      if (!str_to_index.contains(list2[i])) {
        continue;
      }
      int index_sum = i + str_to_index[list2[i]];
      if (index_sum < least_index_sum) {
        least_index_sum = index_sum;
        common_strings.clear();
        common_strings.push_back(list2[i]);
      } else if (index_sum == least_index_sum) {
        common_strings.push_back(list2[i]);
      }
    }
    return common_strings;
  }
};
