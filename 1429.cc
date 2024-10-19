#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class FirstUnique {
 public:
  FirstUnique(vector<int>& nums) {
    for (const auto num : nums) {
      q.push(num);
      ++counts[num];
    }
  }

  int showFirstUnique() {
    while (!q.empty() && counts[q.front()] > 1) {
      q.pop();
    }
    return q.empty() ? -1 : q.front();
  }

  void add(int value) {
    ++counts[value];
    if (counts[value] <= 1) {
      q.push(value);
    }
  }

 private:
  queue<int> q;
  unordered_map<int, int> counts;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
