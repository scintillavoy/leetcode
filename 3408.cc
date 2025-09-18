#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class TaskManager {
 public:
  TaskManager(vector<vector<int>>& tasks) {
    for (int i = 0; i < tasks.size(); ++i) {
      int userId = tasks[i][0];
      int taskId = tasks[i][1];
      int priority = tasks[i][2];
      tasksByPriority[priority][taskId] = userId;
      taskIdToPriority[taskId] = priority;
    }
  }

  void add(int userId, int taskId, int priority) {
    tasksByPriority[priority][taskId] = userId;
    taskIdToPriority[taskId] = priority;
  }

  void edit(int taskId, int newPriority) {
    int oldPriority = taskIdToPriority[taskId];
    int userId = tasksByPriority[oldPriority][taskId];
    tasksByPriority[oldPriority].erase(taskId);
    if (tasksByPriority[oldPriority].empty()) {
      tasksByPriority.erase(oldPriority);
    }
    tasksByPriority[newPriority][taskId] = userId;
    taskIdToPriority[taskId] = newPriority;
  }

  void rmv(int taskId) {
    int priority = taskIdToPriority[taskId];
    tasksByPriority[priority].erase(taskId);
    if (tasksByPriority[priority].empty()) {
      tasksByPriority.erase(priority);
    }
    taskIdToPriority.erase(taskId);
  }

  int execTop() {
    if (tasksByPriority.empty()) {
      return -1;
    }
    auto it = tasksByPriority.rbegin();
    int priority = it->first;
    map<int, int>& tasksWithHighestPriority = it->second;
    auto it2 = tasksWithHighestPriority.rbegin();
    int taskId = it2->first;
    int userId = it2->second;
    tasksWithHighestPriority.erase(taskId);
    if (tasksWithHighestPriority.empty()) {
      tasksByPriority.erase(priority);
    }
    taskIdToPriority.erase(taskId);
    return userId;
  }

 private:
  map<int, map<int, int>> tasksByPriority;
  unordered_map<int, int> taskIdToPriority;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
