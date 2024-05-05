#include <map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int oddEvenJumps(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> next_index(n);
    map<int, int> m;
    next_index[n - 1] = {-1, -1};
    m[arr[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
      // Odd jumps
      auto it = m.lower_bound(arr[i]);
      if (it == m.end()) {
        next_index[i].first = -1;
      } else {
        next_index[i].first = it->second;
      }

      // Even jumps
      it = m.upper_bound(arr[i]);
      if (it != m.begin()) {
        --it;
      }
      if (!(arr[i] >= it->first)) {
        next_index[i].second = -1;
      } else {
        next_index[i].second = it->second;
      }

      m[arr[i]] = i;
    }

    vector<pair<bool, bool>> good(n);
    good[n - 1] = {true, true};
    for (int i = n - 2; i >= 0; --i) {
      if (next_index[i].first == -1) {
        good[i].first = false;
      } else {
        good[i].first = good[next_index[i].first].second;
      }
      if (next_index[i].second == -1) {
        good[i].second = false;
      } else {
        good[i].second = good[next_index[i].second].first;
      }
    }

    int good_count = 0;
    for (int i = 0; i < n; ++i) {
      if (good[i].first) {
        ++good_count;
      }
    }
    return good_count;
  }
};
