#include <vector>
using namespace std;

class FenwickTree {
 private:
  vector<int> tree;

 public:
  FenwickTree(int size) : tree(size + 1, 0) {}

  void update(int index, int delta) {
    ++index;
    while (index < tree.size()) {
      tree[index] += delta;
      index += index & (~index + 1);
    }
  }

  int query(int index) {
    ++index;
    int result = 0;
    while (index > 0) {
      result += tree[index];
      index -= index & (~index + 1);
    }
    return result;
  }
};

class Solution {
 public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> indices2(n), indices2_to_indices1(n);
    for (int i = 0; i < n; ++i) {
      indices2[nums2[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
      indices2_to_indices1[indices2[nums1[i]]] = i;
    }
    FenwickTree tree(n);
    long long num_of_good_triplets = 0;
    for (int value = 0; value < n; ++value) {
      int pos = indices2_to_indices1[value];
      int left = tree.query(pos);
      tree.update(pos, 1);
      int right = (n - 1 - pos) - (value - left);
      num_of_good_triplets += (long long)left * right;
    }
    return num_of_good_triplets;
  }
};
