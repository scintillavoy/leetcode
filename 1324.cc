#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> printVertically(string s) {
    vector<string> result;
    istringstream iss(s);
    string word;
    int iteration = 0;
    while (iss >> word) {
      for (int i = 0; i < word.size(); ++i) {
        if (i < result.size()) {
          result[i] += string(iteration - result[i].size(), ' ') + word[i];
        } else {
          result.push_back(string(iteration, ' ') + word[i]);
        }
      }
      ++iteration;
    }
    return result;
  }
};
