#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long countOfSubstrings(string word, int k) {
    vector<int> next_consonant_indices(word.size());
    int next_consonant_index = word.size();
    for (int i = next_consonant_indices.size() - 1; i >= 0; --i) {
      next_consonant_indices[i] = next_consonant_index;
      if (!is_vowel(word[i])) {
        next_consonant_index = i;
      }
    }
    long long result = 0;
    unordered_map<char, int> num_of_vowels;
    int num_of_consonants = 0;
    int left = 0;
    for (int right = 0; right < word.size(); ++right) {
      if (is_vowel(word[right])) {
        ++num_of_vowels[word[right]];
      } else {
        ++num_of_consonants;
      }
      while (num_of_consonants > k) {
        if (is_vowel(word[left])) {
          --num_of_vowels[word[left]];
          if (num_of_vowels[word[left]] == 0) {
            num_of_vowels.erase(word[left]);
          }
        } else {
          --num_of_consonants;
        }
        ++left;
      }
      while (left < word.size() && num_of_vowels.size() == 5 &&
             num_of_consonants == k) {
        result += next_consonant_indices[right] - right;
        if (is_vowel(word[left])) {
          --num_of_vowels[word[left]];
          if (num_of_vowels[word[left]] == 0) {
            num_of_vowels.erase(word[left]);
          }
        } else {
          --num_of_consonants;
        }
        ++left;
      }
    }
    return result;
  }

 private:
  bool is_vowel(char c) {
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
    }
    return false;
  }
};
