#include <cctype>
#include <sstream>
#include <string>
using namespace std;

class Solution {
 public:
  bool areNumbersAscending(string s) {
    int last_num = 0;
    istringstream iss(s);
    string word;
    while (iss >> word) {
      if (isdigit(word[0])) {
        int num = stoi(word);
        if (last_num >= num) {
          return false;
        }
        last_num = num;
      }
    }
    return true;
  }
};
