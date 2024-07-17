#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) {
      return result;
    }
    string letters;
    backtrack(digits, 0, letters, result);
    return result;
  }

 private:
  vector<vector<char>> digit_to_letters{{'a', 'b', 'c'}, {'d', 'e', 'f'},
                                        {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                        {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                        {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

  void backtrack(string& digits, int index, string& letters,
                 vector<string>& result) {
    if (index == digits.size()) {
      result.push_back(letters);
      return;
    }
    for (const auto letter : digit_to_letters[digits[index] - '2']) {
      letters.push_back(letter);
      backtrack(digits, index + 1, letters, result);
      letters.pop_back();
    }
  }
};
