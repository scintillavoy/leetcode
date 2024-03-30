#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
using namespace std;

class Logger {
 public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, string message) {
    while (!dq.empty()) {
      auto [msg, t] = dq.front();
      if (timestamp < t + 10) {
        break;
      }
      dq.pop();
      s.erase(msg);
    }

    if (s.count(message) != 0) {
      return false;
    }
    dq.push({message, timestamp});
    s.insert(message);
    return true;
  }

 private:
  unordered_set<string> s;
  queue<pair<string, int>> dq;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
