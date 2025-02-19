#include <string>
using namespace std;

class Solution {
 public:
  string getHappyString(int n, int k) {
    int count = 0;
    string happy_string;
    find(n, k, count, happy_string);
    return happy_string;
  }

 private:
  bool find(int n, int k, int &count, string &str) {
    if (str.size() == n) {
      ++count;
      return count == k;
    }
    for (int i = 0; i < 3; ++i) {
      char next_char = 'a' + i;
      if (!str.empty() && str.back() == next_char) {
        continue;
      }
      str.push_back(next_char);
      if (find(n, k, count, str)) {
        return true;
      }
      str.pop_back();
    }
    return false;
  }
};
