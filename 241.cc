#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> diffWaysToCompute(string expression) {
    return find_ways(expression, 0, expression.size());
  }

 private:
  vector<int> find_ways(const string &expression, int start, int end) {
    vector<int> result;
    int length = end - start;
    if (length == 0) {
      return result;
    }
    if (length <= 2) {
      result.push_back(stoi(expression.substr(start, length)));
      return result;
    }
    for (int i = start; i < end; ++i) {
      if (isdigit(expression[i])) {
        continue;
      }
      vector<int> left_result = find_ways(expression, start, i);
      vector<int> right_result = find_ways(expression, i + 1, end);
      for (const auto left_value : left_result) {
        for (const auto right_value : right_result) {
          switch (expression[i]) {
            case '+':
              result.push_back(left_value + right_value);
              break;
            case '-':
              result.push_back(left_value - right_value);
              break;
            case '*':
              result.push_back(left_value * right_value);
              break;
          }
        }
      }
    }
    return result;
  }
};
