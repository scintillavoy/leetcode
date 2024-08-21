#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<Car> cars(n);
    for (int i = 0; i < n; ++i) {
      cars[i] = {position[i], speed[i]};
    }
    sort(cars.begin(), cars.end());
    int num_of_fleets = n;
    vector<double> durations(n);
    durations[n - 1] =
        (double)(target - cars[n - 1].position) / cars[n - 1].speed;
    for (int i = n - 2; i >= 0; --i) {
      durations[i] = (double)(target - cars[i].position) / cars[i].speed;
      if (durations[i] <= durations[i + 1]) {
        --num_of_fleets;
        durations[i] = durations[i + 1];
      }
    }
    return num_of_fleets;
  }

 private:
  struct Car {
    int position;
    int speed;

    bool operator<(const Car& other) const { return position < other.position; }
  };
};
