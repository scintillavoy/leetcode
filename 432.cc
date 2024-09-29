#include <algorithm>
#include <limits>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class AllOne {
 public:
  AllOne() {}

  void inc(string key) {
    ++string_to_count[key];
    int new_count = string_to_count[key];
    max_count = max(max_count, new_count);
    if (new_count == 1) {
      min_count = 1;
    } else {
      count_to_strings[new_count - 1].erase(key);
      if (count_to_strings[new_count - 1].empty()) {
        count_to_strings.erase(new_count - 1);
        if (min_count == new_count - 1) {
          ++min_count;
        }
      }
    }
    count_to_strings[new_count].insert(key);
  }

  void dec(string key) {
    --string_to_count[key];
    int new_count = string_to_count[key];
    count_to_strings[new_count + 1].erase(key);
    if (count_to_strings[new_count + 1].empty()) {
      count_to_strings.erase(new_count + 1);
      if (max_count == new_count + 1) {
        --max_count;
      }
    }
    if (new_count == 0) {
      string_to_count.erase(key);
      if (!count_to_strings.contains(new_count + 1)) {
        min_count = numeric_limits<int>::max();
        for (const auto &[count, _] : count_to_strings) {
          min_count = min(min_count, count);
        }
      }
    } else {
      count_to_strings[new_count].insert(key);
      min_count = min(min_count, new_count);
    }
  }

  string getMaxKey() {
    if (max_count == 0) {
      return "";
    }
    return *count_to_strings[max_count].begin();
  }

  string getMinKey() {
    if (min_count == numeric_limits<int>::max()) {
      return "";
    }
    return *count_to_strings[min_count].begin();
  }

 private:
  unordered_map<string, int> string_to_count;
  unordered_map<int, unordered_set<string>> count_to_strings;
  int max_count = 0;
  int min_count = numeric_limits<int>::max();
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
