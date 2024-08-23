#include <cctype>
#include <numeric>
#include <string>
using namespace std;

class Solution {
 public:
  string fractionAddition(string expression) {
    int running_numerator = 0, running_denominator = 1;
    int index = 0;
    while (index < expression.size()) {
      // Parse a sign.
      int sign = 1;
      if (!isdigit(expression[index])) {
        if (expression[index] == '-') {
          sign = -1;
        }
        ++index;
      }
      // Parse a numerator.
      int numerator = 0;
      while (index < expression.size() && isdigit(expression[index])) {
        numerator = numerator * 10 + expression[index] - '0';
        ++index;
      }
      numerator *= sign;
      // Skip '/'.
      ++index;
      // Parse a denominator.
      int denominator = 0;
      while (index < expression.size() && isdigit(expression[index])) {
        denominator = denominator * 10 + expression[index] - '0';
        ++index;
      }
      // Add to the running fraction.
      running_numerator =
          running_numerator * denominator + numerator * running_denominator;
      running_denominator *= denominator;
    }
    // Reduce the fraction.
    int gcd_value = gcd(running_numerator, running_denominator);
    running_numerator /= gcd_value;
    running_denominator /= gcd_value;
    return to_string(running_numerator) + '/' + to_string(running_denominator);
  }
};
