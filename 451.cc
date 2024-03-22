#include <algorithm>
#include <cctype>
#include <functional>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    vector<pair<int, int>> frequency(62);
    for (int i = 0; i < 10; ++i) {
      frequency[i].second = i + '0';
    }
    for (int i = 0; i < 26; ++i) {
      frequency[i + 10].second = i + 'A';
    }
    for (int i = 0; i < 26; ++i) {
      frequency[i + 36].second = i + 'a';
    }
    for (const auto &c : s) {
      ++frequency[getIndex(c)].first;
    }
    sort(frequency.begin(), frequency.end(), greater<pair<int, int>>());
    string answer;
    for (auto [count, c] : frequency) {
      answer += string(count, c);
    }
    return answer;
  }

 private:
  int getIndex(char c) {
    if (isdigit(c)) {
      return c - '0';
    } else if (isupper(c)) {
      return c - 'A' + 10;
    } else {
      return c - 'a' + 36;
    }
  }
};
