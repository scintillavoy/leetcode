#include <cmath>
#include <string>
using namespace std;

class Solution {
 public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                string s) {
    return count(to_string(finish), limit, s) -
           count(to_string(start - 1), limit, s);
  }

 private:
  long long count(const string& finish, int limit, const string& s) {
    if (finish.size() < s.size()) {
      return 0;
    }
    if (finish.size() == s.size()) {
      return finish >= s ? 1 : 0;
    }
    long long result = 0;
    int length_diff = finish.size() - s.size();
    long long multiplier = pow(limit + 1, length_diff);
    for (int i = 0; i < length_diff; ++i) {
      if (limit < finish[i] - '0') {
        result += multiplier;
        return result;
      }
      multiplier /= limit + 1;
      result += (finish[i] - '0') * multiplier;
    }
    if (finish.substr(length_diff, s.size()) >= s) {
      ++result;
    }
    return result;
  }
};
