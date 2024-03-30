#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> frequency;
    int answer = 0;
    int left = 0;
    for (int right = 0; right < s.size(); ++right) {
      ++frequency[s[right]];
      while (frequency.size() > k) {
        --frequency[s[left]];
        if (frequency[s[left]] == 0) {
          frequency.erase(s[left]);
        }
        ++left;
      }
      answer = max(answer, right - left + 1);
    }
    return answer;
  }
};
