#include <string>
using namespace std;

class Solution {
 public:
  string compressedString(string word) {
    string compressed;
    int count = 0;
    for (int i = 0; i < word.size(); ++i) {
      if (count == 9 || (i > 0 && word[i - 1] != word[i])) {
        compressed += count + '0';
        compressed += word[i - 1];
        count = 0;
      }
      ++count;
    }
    compressed += count + '0';
    compressed += word.back();
    return compressed;
  }
};
