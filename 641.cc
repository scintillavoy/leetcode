#include <deque>
using namespace std;

class MyCircularDeque {
 public:
  MyCircularDeque(int k) { capacity = k; }

  bool insertFront(int value) {
    if (isFull()) {
      return false;
    }
    dq.push_front(value);
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) {
      return false;
    }
    dq.push_back(value);
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) {
      return false;
    }
    dq.pop_front();
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) {
      return false;
    }
    dq.pop_back();
    return true;
  }

  int getFront() { return isEmpty() ? -1 : dq.front(); }

  int getRear() { return isEmpty() ? -1 : dq.back(); }

  bool isEmpty() { return dq.size() == 0; }

  bool isFull() { return dq.size() == capacity; }

 private:
  int capacity;
  deque<int> dq;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
