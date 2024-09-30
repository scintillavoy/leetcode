#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

class CustomStack {
 public:
  CustomStack(int maxSize) { max_size = maxSize; }

  void push(int x) {
    if (stk.size() == max_size) {
      return;
    }
    stk.push(x);
  }

  int pop() {
    if (stk.empty()) {
      return -1;
    }
    int result = stk.top();
    if (increments.contains(stk.size())) {
      result += increments[stk.size()];
      if (stk.size() > 1) {
        increments[stk.size() - 1] += increments[stk.size()];
      }
      increments.erase(stk.size());
    }
    stk.pop();
    return result;
  }

  void increment(int k, int val) {
    k = min(k, (int)stk.size());
    if (k <= 0) {
      return;
    }
    increments[k] += val;
  }

 private:
  int max_size;
  stack<int> stk;
  unordered_map<int, int> increments;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
