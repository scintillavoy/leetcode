#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string mapWordWeights(vector<string>& words, vector<int>& weights) {
    string result;
    for (const auto& word : words) {
      int sum = 0;
      for (const auto ch : word) {
        sum += weights[ch - 'a'];
      }
      result.push_back('z' - sum % 26);
    }
    return result;
  }
};
