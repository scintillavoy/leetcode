#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> decrypted(n);
    int left, right;
    if (k > 0) {
      left = 1;
      right = k;
    } else if (k < 0) {
      left = n + k;
      right = n - 1;
    } else {
      return decrypted;
    }
    int sum = 0;
    for (int i = left; i <= right; ++i) {
      sum += code[i];
    }
    for (int i = 0; i < n; ++i) {
      decrypted[i] = sum;
      sum -= code[left];
      left = (left + 1) % n;
      right = (right + 1) % n;
      sum += code[right];
    }
    return decrypted;
  }
};
