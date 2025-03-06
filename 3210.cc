#include <string>
using namespace std;

class Solution {
 public:
  string getEncryptedString(string s, int k) {
    string encrypted;
    for (int i = 0; i < s.size(); ++i) {
      encrypted.push_back(s[(i + k) % s.size()]);
    }
    return encrypted;
  }
};
