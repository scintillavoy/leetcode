#include <unordered_map>
using namespace std;

class Solution {
 public:
  int countLargestGroup(int n) {
    unordered_map<int, int> groups;
    for (int i = 1; i <= n; ++i) {
      ++groups[find_sum_of_digits(i)];
    }
    int max_size = 0;
    int num_of_groups = 0;
    for (const auto [key, size] : groups) {
      if (max_size < size) {
        max_size = size;
        num_of_groups = 1;
      } else if (max_size == size) {
        ++num_of_groups;
      }
    }
    return num_of_groups;
  }

 private:
  int find_sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
};
