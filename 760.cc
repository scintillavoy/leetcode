#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, vector<int>> num_to_indices;
    for (int i = 0; i < nums2.size(); ++i) {
      num_to_indices[nums2[i]].push_back(i);
    }
    vector<int> mappings(nums1.size());
    for (int i = 0; i < nums1.size(); ++i) {
      mappings[i] = num_to_indices[nums1[i]].back();
      num_to_indices[nums1[i]].pop_back();
    }
    return mappings;
  }
};
