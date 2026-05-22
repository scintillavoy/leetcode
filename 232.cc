#include <stack>
using namespace std;

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { stk1.push(x); }

  int pop() {
    move();
    int t = stk2.top();
    stk2.pop();
    return t;
  }

  int peek() {
    move();
    return stk2.top();
  }

  bool empty() { return stk1.empty() && stk2.empty(); }

 private:
  stack<int> stk1;
  stack<int> stk2;

  void move() {
    if (!stk2.empty()) {
      return;
    }
    while (!stk1.empty()) {
      stk2.push(stk1.top());
      stk1.pop();
    }
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
