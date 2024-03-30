#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    string answer;
    vector<pair<int, string>> vec{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"},
    };
    for (int i = 0; i < vec.size(); ++i) {
      while (num >= vec[i].first) {
        num -= vec[i].first;
        answer += vec[i].second;
      }
    }
    return answer;
  }
};
