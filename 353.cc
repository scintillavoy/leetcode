#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class SnakeGame {
 public:
  SnakeGame(int width, int height, vector<vector<int>>& food)
      : width(width), height(height), food(food) {
    position_set.insert("0,0");
    position_queue.push({0, 0});
  }

  int move(string direction) {
    pair<int, int> next_position = position_queue.back();
    switch (direction[0]) {
      case 'U':
        --next_position.first;
        break;
      case 'D':
        ++next_position.first;
        break;
      case 'L':
        --next_position.second;
        break;
      case 'R':
        ++next_position.second;
        break;
    }
    if (score < food.size() && food[score][0] == next_position.first &&
        food[score][1] == next_position.second) {
      ++score;
    } else {
      position_set.erase(pair_to_string(position_queue.front()));
      position_queue.pop();
    }
    if (next_position.first < 0 || next_position.first >= height ||
        next_position.second < 0 || next_position.second >= width ||
        position_set.contains(pair_to_string(next_position))) {
      return -1;
    }
    position_set.insert(pair_to_string(next_position));
    position_queue.push(next_position);
    return score;
  }

 private:
  int width;
  int height;
  vector<vector<int>> food;
  int score = 0;
  unordered_set<string> position_set;
  queue<pair<int, int>> position_queue;

  string pair_to_string(pair<int, int> p) {
    return to_string(p.first) + ',' + to_string(p.second);
  }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
