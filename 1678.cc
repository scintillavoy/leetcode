#include <string>
using namespace std;

class Solution {
 public:
  string interpret(string command) {
    string result;
    int index = 0;
    while (index < command.size()) {
      if (command[index] == 'G') {
        result += 'G';
        ++index;
        continue;
      }
      if (command[index + 1] == ')') {
        result += 'o';
        index += 2;
        continue;
      }
      result += "al";
      index += 4;
    }
    return result;
  }
};
