#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string findSmallestRegion(vector<vector<string>>& regions, string region1,
                            string region2) {
    unordered_map<string, string> parents;
    for (const auto& region : regions) {
      for (int i = 1; i < region.size(); ++i) {
        parents[region[i]] = region[0];
      }
    }
    int height1 = get_height(region1, parents);
    int height2 = get_height(region2, parents);
    while (height1 != height2) {
      if (height1 > height2) {
        --height1;
        region1 = parents[region1];
      } else {
        --height2;
        region2 = parents[region2];
      }
    }
    while (region1 != region2) {
      region1 = parents[region1];
      region2 = parents[region2];
    }
    return region1;
  }

 private:
  int get_height(string region, const unordered_map<string, string>& parents) {
    int height = 0;
    while (parents.contains(region)) {
      ++height;
      region = parents.at(region);
    }
    return height;
  }
};
