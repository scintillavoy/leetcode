#include <cctype>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    unordered_set<string> original_words;
    unordered_map<string, string> lowercased_to_original;
    unordered_map<string, string> wildcard_to_original;
    for (const auto& word : wordlist) {
      original_words.insert(word);
      string lowercased = to_lowercase(word);
      if (!lowercased_to_original.contains(lowercased)) {
        lowercased_to_original[lowercased] = word;
      }
      string word_with_wildcards = replace_vowels_with_wildcard(lowercased);
      if (!wildcard_to_original.contains(word_with_wildcards)) {
        wildcard_to_original[word_with_wildcards] = word;
      }
    }
    vector<string> result(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      if (original_words.contains(queries[i])) {
        result[i] = queries[i];
        continue;
      }
      string lowercased = to_lowercase(queries[i]);
      if (lowercased_to_original.contains(lowercased)) {
        result[i] = lowercased_to_original[lowercased];
        continue;
      }
      string word_with_wildcards = replace_vowels_with_wildcard(lowercased);
      if (wildcard_to_original.contains(word_with_wildcards)) {
        result[i] = wildcard_to_original[word_with_wildcards];
        continue;
      }
    }
    return result;
  }

 private:
  string to_lowercase(string word) {
    for (int i = 0; i < word.size(); ++i) {
      word[i] = tolower(word[i]);
    }
    return word;
  }

  string replace_vowels_with_wildcard(string word) {
    for (int i = 0; i < word.size(); ++i) {
      if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
          word[i] == 'o' || word[i] == 'u') {
        word[i] = '*';
      }
    }
    return word;
  }
};
