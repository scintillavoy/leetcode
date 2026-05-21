#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for (const auto& token : tokens) {
      if (('0' <= token[0] && token[0] <= '9') ||
          (token[0] == '-' && token.size() > 1)) {
        nums.push(stoi(token));
        continue;
      }
      int right_operand = nums.top();
      nums.pop();
      int left_operand = nums.top();
      nums.pop();
      if (token == "+") {
        nums.push(left_operand + right_operand);
      } else if (token == "-") {
        nums.push(left_operand - right_operand);
      } else if (token == "*") {
        nums.push(left_operand * right_operand);
      } else if (token == "/") {
        nums.push(left_operand / right_operand);
      }
    }
    return nums.top();
  }
};
