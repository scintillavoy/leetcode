#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_set<string> cities;
    for (const auto& path : paths) {
      cities.insert(path[0]);
    }
    for (const auto& path : paths) {
      if (cities.count(path[1]) == 0) {
        return path[1];
      }
    }
    return "";
  }
};
