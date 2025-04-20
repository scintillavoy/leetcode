#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> counts;
    for (const auto answer : answers) {
      ++counts[answer];
    }
    int result = answers.size();
    for (const auto [k, v] : counts) {
      if (v % (k + 1) != 0) {
        result += k + 1 - v % (k + 1);
      }
    }
    return result;
  }
};
