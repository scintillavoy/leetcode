#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool checkIfPangram(string sentence) {
    unordered_set<char> occurrence;
    for (const auto c : sentence) {
      occurrence.insert(c);
    }
    return occurrence.size() == 26;
  }
};
