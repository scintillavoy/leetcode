#include <vector>
using namespace std;

class Street {
 public:
  Street(vector<int> doors);
  void openDoor();
  void closeDoor();
  bool isDoorOpen();
  void moveRight();
  void moveLeft();
};

/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
 public:
  int houseCount(Street* street, int k) {
    for (int i = 0; i < k - 1; ++i) {
      street->openDoor();
      street->moveLeft();
    }
    street->closeDoor();
    street->moveLeft();
    int num_of_houses = 1;
    while (street->isDoorOpen()) {
      ++num_of_houses;
      street->closeDoor();
      street->moveLeft();
    }
    return num_of_houses;
  }
};
