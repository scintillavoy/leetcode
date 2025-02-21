#include <iterator>
#include <map>
using namespace std;

class MRUQueue {
 public:
  MRUQueue(int n) {
    for (int i = 1; i <= n; ++i) {
      m[i] = i;
    }
    next_counter = n + 1;
  }

  int fetch(int k) {
    auto [counter, num] = *next(m.begin(), k - 1);
    m.erase(counter);
    m[next_counter] = num;
    ++next_counter;
    return num;
  }

 private:
  map<int, int> m;
  int next_counter;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
