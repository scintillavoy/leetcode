#include <vector>
using namespace std;

class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int total_hamming_distance = 0;
    vector<int> num_of_set_bits;
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      int bit_count = 0;
      while (num > 0) {
        if (bit_count >= num_of_set_bits.size()) {
          num_of_set_bits.push_back(0);
        }
        if ((num & 1) == 1) {
          total_hamming_distance += i - num_of_set_bits[bit_count];
          ++num_of_set_bits[bit_count];
        } else {
          total_hamming_distance += num_of_set_bits[bit_count];
        }
        num >>= 1;
        ++bit_count;
      }
      while (bit_count < num_of_set_bits.size()) {
        total_hamming_distance += num_of_set_bits[bit_count];
        ++bit_count;
      }
    }
    return total_hamming_distance;
  }
};
