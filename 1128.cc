#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int num_of_pairs = 0;
    unordered_map<int, int> count;
    for (const auto& domino : dominoes) {
      int num1 = domino[0];
      int num2 = domino[1];
      if (num1 > num2) {
        swap(num1, num2);
      }
      int key = num1 * 10 + num2;
      num_of_pairs += count[key];
      ++count[key];
    }
    return num_of_pairs;
  }
};
