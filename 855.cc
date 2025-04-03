#include <set>
using namespace std;

class ExamRoom {
 public:
  ExamRoom(int n) : n(n) {}

  int seat() {
    int new_seat = 0;
    if (!occupied_seats.empty()) {
      auto it = occupied_seats.begin();
      int max_distance = *it;
      int prev = *it;
      ++it;
      while (it != occupied_seats.end()) {
        int curr_distance = (*it - prev) / 2;
        if (max_distance < curr_distance) {
          max_distance = curr_distance;
          new_seat = (*it + prev) / 2;
        }
        prev = *it;
        ++it;
      }
      if (max_distance < n - 1 - prev) {
        max_distance = n - 1 - prev;
        new_seat = n - 1;
      }
    }
    occupied_seats.insert(new_seat);
    return new_seat;
  }

  void leave(int p) { occupied_seats.erase(p); }

 private:
  int n;
  set<int> occupied_seats;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
