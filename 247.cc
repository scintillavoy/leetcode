#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findStrobogrammatic(int n) {
    vector<string> answer;
    string num;
    backtrack(num, n, answer);
    return answer;
  }

 private:
  const char digits[5] = {'0', '1', '8', '6', '9'};

  void backtrack(string &num, int n, vector<string> &answer) {
    if (num.size() == n / 2) {
      if (n % 2 == 0) {
        for (int i = num.size() - 1; i >= 0; --i) {
          switch (num[i]) {
            case '0':
            case '1':
            case '8':
              num.push_back(num[i]);
              break;
            case '6':
              num.push_back('9');
              break;
            case '9':
              num.push_back('6');
              break;
          }
        }
        answer.push_back(num);
        for (int i = 0; i < n / 2; ++i) {
          num.pop_back();
        }
      } else {
        num.push_back('0');
        for (int i = (int)num.size() - 2; i >= 0; --i) {
          switch (num[i]) {
            case '0':
            case '1':
            case '8':
              num.push_back(num[i]);
              break;
            case '6':
              num.push_back('9');
              break;
            case '9':
              num.push_back('6');
              break;
          }
        }
        answer.push_back(num);
        num[n / 2] = '1';
        answer.push_back(num);
        num[n / 2] = '8';
        answer.push_back(num);
        for (int i = 0; i <= n / 2; ++i) {
          num.pop_back();
        }
      }
      return;
    }
    for (int i = (num.empty() ? 1 : 0); i < 5; ++i) {
      num.push_back(digits[i]);
      backtrack(num, n, answer);
      num.pop_back();
    }
  }
};
