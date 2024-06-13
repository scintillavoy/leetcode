#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
    int n = arrival.size();
    vector<int> answer(n);
    int next_person = 0;
    for (int current_time = arrival[0];
         next_person < n || !entering.empty() || !exiting.empty();
         ++current_time) {
      if (entering.empty() && exiting.empty() &&
          current_time < arrival[next_person]) {
        current_time = arrival[next_person];
        last_state = -1;
      }
      while (next_person < n && current_time == arrival[next_person]) {
        Person person{next_person, arrival[next_person], state[next_person]};
        if (person.state == 0) {
          entering.push_back(person);
        } else {
          exiting.push_back(person);
        }
        ++next_person;
      }
      if (last_state == -1) {
        if (!exiting.empty()) {
          pop_exiting(answer, current_time);
        } else {
          pop_entering(answer, current_time);
        }
      } else if (last_state == 0) {
        if (!entering.empty()) {
          pop_entering(answer, current_time);
        } else {
          pop_exiting(answer, current_time);
        }
      } else if (last_state == 1) {
        if (!exiting.empty()) {
          pop_exiting(answer, current_time);
        } else {
          pop_entering(answer, current_time);
        }
      }
    }
    return answer;
  }

 private:
  struct Person {
    int index;
    int arrival;
    int state;
  };

  int last_state = -1;
  deque<Person> entering, exiting;

  void pop_exiting(vector<int>& answer, int time) {
    Person p = exiting.front();
    exiting.pop_front();
    answer[p.index] = time;
    last_state = 1;
  }

  void pop_entering(vector<int>& answer, int time) {
    Person p = entering.front();
    entering.pop_front();
    answer[p.index] = time;
    last_state = 0;
  }
};
