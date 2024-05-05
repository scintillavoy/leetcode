#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Employee {
 public:
  int id;
  int importance;
  vector<int> subordinates;
};

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, int> id_to_index;
    for (int i = 0; i < employees.size(); ++i) {
      id_to_index[employees[i]->id] = i;
    }
    queue<int> q;
    q.push(id);
    int total = 0;
    while (!q.empty()) {
      Employee* employee = employees[id_to_index[q.front()]];
      q.pop();
      total += employee->importance;
      for (const auto subordinate : employee->subordinates) {
        q.push(subordinate);
      }
    }
    return total;
  }
};
