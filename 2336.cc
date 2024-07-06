#include <queue>
#include <unordered_set>
using namespace std;

class SmallestInfiniteSet {
 public:
  SmallestInfiniteSet() { pq.push(1); }

  int popSmallest() {
    int smallest = pq.top();
    pq.pop();
    if (pq.empty()) {
      pq.push(smallest + 1);
    }
    missing.insert(smallest);
    return smallest;
  }

  void addBack(int num) {
    if (missing.count(num) != 0) {
      pq.push(num);
      missing.erase(num);
    }
  }

 private:
  priority_queue<int, vector<int>, greater<int>> pq;
  unordered_set<int> missing;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
