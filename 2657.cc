#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    unordered_set<int> s;
    vector<int> result(n);
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (s.contains(A[i])) {
        ++count;
      } else {
        s.insert(A[i]);
      }
      if (s.contains(B[i])) {
        ++count;
      } else {
        s.insert(B[i]);
      }
      result[i] = count;
    }
    return result;
  }
};
