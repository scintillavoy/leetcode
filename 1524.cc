#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    int num_of_subarrays = 0;
    int odd_count = 0;
    int even_count = 1;
    int running_sum = 0;
    for (const auto num : arr) {
      running_sum += num;
      if (running_sum % 2 == 0) {
        num_of_subarrays += odd_count;
        ++even_count;
      } else {
        num_of_subarrays += even_count;
        ++odd_count;
      }
      num_of_subarrays %= MOD;
    }
    return num_of_subarrays;
  }
};
