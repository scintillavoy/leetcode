#include <cmath>
#include <vector>
using namespace std;

#define SIZE 101

class Solution {
 public:
  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    int n = seats.size();
    vector<int> seat_count(SIZE), student_count(SIZE);
    for (int i = 0; i < n; ++i) {
      ++seat_count[seats[i]];
      ++student_count[students[i]];
    }
    int seat_index = 0, student_index = 0;
    int result = 0;
    while (true) {
      while (seat_index < SIZE && seat_count[seat_index] == 0) {
        ++seat_index;
      }
      while (student_index < SIZE && student_count[student_index] == 0) {
        ++student_index;
      }
      if (seat_index == SIZE && student_index == SIZE) {
        break;
      }
      int min_count = min(seat_count[seat_index], student_count[student_index]);
      seat_count[seat_index] -= min_count;
      student_count[student_index] -= min_count;
      result += min_count * abs(seat_index - student_index);
    }
    return result;
  }
};
