#include <sstream>
#include <string>
using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    istringstream iss1(version1), iss2(version2);
    while (true) {
      string rev1_str, rev2_str;
      bool end1 = false, end2 = false;
      if (!getline(iss1, rev1_str, '.')) {
        end1 = true;
        rev1_str = "0";
      }
      if (!getline(iss2, rev2_str, '.')) {
        end2 = true;
        rev2_str = "0";
      }
      if (end1 && end2) {
        break;
      }
      int rev1 = stoi(rev1_str);
      int rev2 = stoi(rev2_str);
      if (rev1 < rev2) {
        return -1;
      } else if (rev1 > rev2) {
        return 1;
      }
    }
    return 0;
  }
};
