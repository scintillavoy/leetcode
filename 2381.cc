#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    vector<int> shifts_by_index(s.size() + 1);
    for (const auto& shift : shifts) {
      int direction = shift[2] == 0 ? -1 : 1;
      shifts_by_index[shift[0]] += direction;
      shifts_by_index[shift[1] + 1] -= direction;
    }
    for (int i = 0; i < s.size(); ++i) {
      int character = s[i] + shifts_by_index[i] % 26;
      if (character < 'a') {
        character += 26;
      } else if (character > 'z') {
        character -= 26;
      }
      s[i] = character;
      shifts_by_index[i + 1] += shifts_by_index[i];
    }
    return s;
  }
};
