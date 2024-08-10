#include <map>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class MaxStack {
 public:
  MaxStack() {}

  void push(int x) {
    stk.push({x, id});
    m[x].push_back(id);
    ++id;
  }

  int pop() {
    auto [value, id] = stk.top();
    stk.pop();
    m[value].pop_back();
    if (m[value].size() == 0) {
      m.erase(value);
    }
    removed.erase(id);
    pop_removed();
    return value;
  }

  int top() { return stk.top().first; }

  int peekMax() { return m.crbegin()->first; }

  int popMax() {
    auto it = m.rbegin();
    int value = it->first;
    int id = it->second.back();
    it->second.pop_back();
    if (it->second.size() == 0) {
      m.erase(value);
    }
    removed.insert(id);
    pop_removed();
    return value;
  }

 private:
  stack<pair<int, int>> stk;
  map<int, vector<int>> m;
  unordered_set<int> removed;
  int id = 0;

  void pop_removed() {
    while (!stk.empty() && removed.count(stk.top().second) > 0) {
      int id = stk.top().second;
      stk.pop();
      removed.erase(id);
    }
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
