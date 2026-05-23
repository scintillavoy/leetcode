#include <vector>
using namespace std;

class MyCircularQueue {
 public:
  MyCircularQueue(int k) { this->vec = vector<int>(k); }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    vec[end] = value;
    end = (end + 1) % vec.size();
    is_empty = false;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    start = (start + 1) % vec.size();
    if (start == end) {
      is_empty = true;
    }
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return vec[start];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return vec[(end - 1 + vec.size()) % vec.size()];
  }

  bool isEmpty() { return is_empty; }

  bool isFull() { return !is_empty && start == end; }

 private:
  vector<int> vec;
  int start = 0;  // inclusive
  int end = 0;    // exclusive
  bool is_empty = true;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
