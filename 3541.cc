#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxFreqSum(string s) {
    vector<int> counts(26);
    for (const auto c : s) {
      ++counts[c - 'a'];
    }
    int max_vowel_count = 0;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for (const auto vowel : vowels) {
      max_vowel_count = max(max_vowel_count, counts[vowel - 'a']);
      counts[vowel - 'a'] = 0;
    }
    int max_consonant_count = *max_element(counts.begin(), counts.end());
    return max_vowel_count + max_consonant_count;
  }
};
