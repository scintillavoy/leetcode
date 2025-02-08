#include <set>
#include <unordered_map>
using namespace std;

class NumberContainers {
 public:
  NumberContainers() {}

  void change(int index, int number) {
    if (index_to_number.contains(index)) {
      int prev_number = index_to_number[index];
      number_to_indices[prev_number].erase(index);
      if (number_to_indices[prev_number].empty()) {
        number_to_indices.erase(prev_number);
      }
    }
    index_to_number[index] = number;
    number_to_indices[number].insert(index);
  }

  int find(int number) {
    if (!number_to_indices.contains(number)) {
      return -1;
    }
    return *number_to_indices[number].begin();
  }

 private:
  unordered_map<int, int> index_to_number;
  unordered_map<int, set<int>> number_to_indices;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
