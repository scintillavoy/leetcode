#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string betterCompression(string compressed) {
    vector<int> frequencies(26);
    for (int i = 0; i < compressed.size();) {
      char c = compressed[i];
      ++i;
      int frequency = 0;
      while (i < compressed.size() && isdigit(compressed[i])) {
        frequency = frequency * 10 + compressed[i] - '0';
        ++i;
      }
      frequencies[c - 'a'] += frequency;
    }
    string result;
    for (int i = 0; i < frequencies.size(); ++i) {
      if (frequencies[i] == 0) {
        continue;
      }
      result += i + 'a';
      result += to_string(frequencies[i]);
    }
    return result;
  }
};
