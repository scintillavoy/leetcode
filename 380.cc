#include <random>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class RandomizedSet {
 public:
  RandomizedSet() {
    random_device rd;
    random_engine.seed(rd());
  }

  bool insert(int val) {
    if (val_to_index.count(val) > 0) {
      return false;
    }
    val_to_index[val] = values.size();
    values.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (val_to_index.count(val) == 0) {
      return false;
    }
    int index = val_to_index[val];
    swap(values[index], values[values.size() - 1]);
    val_to_index[values[index]] = index;
    values.pop_back();
    val_to_index.erase(val);
    return true;
  }

  int getRandom() { return values[random_engine() % values.size()]; }

 private:
  default_random_engine random_engine;
  unordered_map<int, int> val_to_index;
  vector<int> values;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
