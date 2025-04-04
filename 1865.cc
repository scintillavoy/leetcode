#include <unordered_map>
#include <vector>
using namespace std;

class FindSumPairs {
 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    for (const auto num : nums2) {
      ++this->nums2_count[num];
    }
  }

  void add(int index, int val) {
    --nums2_count[nums2[index]];
    nums2[index] += val;
    ++nums2_count[nums2[index]];
  }

  int count(int tot) {
    int count = 0;
    for (const auto num : nums1) {
      count += nums2_count[tot - num];
    }
    return count;
  }

 private:
  vector<int> nums1;
  vector<int> nums2;
  unordered_map<int, int> nums2_count;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
