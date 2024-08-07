#include <deque>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string numberToWords(int num) {
    deque<string> words;
    convert(num, words);
    string result;
    for (const auto &word : words) {
      result += word;
      result += ' ';
    }
    result.pop_back();
    return result;
  }

 private:
  unordered_map<int, string> m{{0, "Zero"},          {1, "One"},
                               {2, "Two"},           {3, "Three"},
                               {4, "Four"},          {5, "Five"},
                               {6, "Six"},           {7, "Seven"},
                               {8, "Eight"},         {9, "Nine"},
                               {10, "Ten"},          {11, "Eleven"},
                               {12, "Twelve"},       {13, "Thirteen"},
                               {14, "Fourteen"},     {15, "Fifteen"},
                               {16, "Sixteen"},      {17, "Seventeen"},
                               {18, "Eighteen"},     {19, "Nineteen"},
                               {20, "Twenty"},       {30, "Thirty"},
                               {40, "Forty"},        {50, "Fifty"},
                               {60, "Sixty"},        {70, "Seventy"},
                               {80, "Eighty"},       {90, "Ninety"},
                               {100, "Hundred"},     {1000, "Thousand"},
                               {1000000, "Million"}, {1000000000, "Billion"}};

  void convert(int num, deque<string> &words) {
    if (num == 0) {
      words.push_front(m[num]);
      return;
    }
    convert_1_to_999(num % 1000, words);
    num /= 1000;
    for (int multiplier = 1; num > 0; num /= 1000) {
      multiplier *= 1000;
      if (num % 1000 > 0) {
        words.push_front(m[multiplier]);
        convert_1_to_999(num % 1000, words);
      }
    }
  }

  void convert_1_to_999(int num, deque<string> &words) {
    if (num % 100 > 0) {
      if (1 <= num % 100 && num % 100 <= 19) {
        words.push_front(m[num % 100]);
      } else {
        if (num % 10 > 0) {
          words.push_front(m[num % 10]);
        }
        words.push_front(m[num / 10 % 10 * 10]);
      }
    }
    num /= 100;
    if (num == 0) {
      return;
    }
    words.push_front(m[100]);
    words.push_front(m[num % 10]);
  }
};
