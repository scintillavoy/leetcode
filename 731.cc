#include <map>
using namespace std;

class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    ++bookings[start];
    --bookings[end];
    int overlapped_bookings = 0;
    for (const auto booking : bookings) {
      overlapped_bookings += booking.second;
      if (overlapped_bookings > max_overlapped_bookings) {
        --bookings[start];
        ++bookings[end];
        if (bookings[start] == 0) {
          bookings.erase(start);
        }
        if (bookings[end] == 0) {
          bookings.erase(end);
        }
        return false;
      }
    }
    return true;
  }

 private:
  static const int max_overlapped_bookings = 2;

  map<int, int> bookings;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
