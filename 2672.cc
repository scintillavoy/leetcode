#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    int num_of_pairs = 0;
    vector<int> result(queries.size());
    unordered_map<int, int> index_to_color;
    for (int i = 0; i < queries.size(); ++i) {
      int index = queries[i][0];
      int new_color = queries[i][1];
      if (index_to_color.contains(index)) {
        if (index_to_color.contains(index - 1) &&
            index_to_color[index] == index_to_color[index - 1]) {
          --num_of_pairs;
        }
        if (index_to_color.contains(index + 1) &&
            index_to_color[index] == index_to_color[index + 1]) {
          --num_of_pairs;
        }
      }
      index_to_color[index] = new_color;
      if (index_to_color.contains(index - 1) &&
          index_to_color[index] == index_to_color[index - 1]) {
        ++num_of_pairs;
      }
      if (index_to_color.contains(index + 1) &&
          index_to_color[index] == index_to_color[index + 1]) {
        ++num_of_pairs;
      }
      result[i] = num_of_pairs;
    }
    return result;
  }
};
