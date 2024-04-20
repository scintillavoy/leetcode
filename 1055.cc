#include <string>
using namespace std;

class Solution {
 public:
  int shortestWay(string source, string target) {
    int answer = 1;
    int i = 0;
    for (int j = 0; j < target.size(); ++j) {
      while (i < source.size() && source[i] != target[j]) {
        ++i;
      }
      if (i == source.size()) {
        ++answer;
        i = 0;
      }
      while (i < source.size() && source[i] != target[j]) {
        ++i;
      }
      if (i == source.size()) {
        return -1;
      }
      ++i;
    }
    return answer;
  }
};
