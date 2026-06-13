#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> reserved_seats(n + 1);
    for (const auto& booking : bookings) {
      int first = booking[0];
      int last = booking[1];
      int seats = booking[2];
      reserved_seats[first - 1] += seats;
      reserved_seats[last] -= seats;
    }
    for (int i = 1; i < n; ++i) {
      reserved_seats[i] += reserved_seats[i - 1];
    }
    reserved_seats.pop_back();
    return reserved_seats;
  }
};
