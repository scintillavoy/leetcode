#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n);
    stack<int> function_ids;
    int current_time = 0;
    for (const auto& log : logs) {
      istringstream iss(log);
      vector<string> tokens;
      string token;
      while (getline(iss, token, ':')) {
        tokens.push_back(token);
      }
      int function_id = stoi(tokens[0]);
      string type = tokens[1];
      int timestamp = stoi(tokens[2]);
      if (type == "start") {
        if (!function_ids.empty()) {
          result[function_ids.top()] += timestamp - current_time;
        }
        function_ids.push(function_id);
        current_time = timestamp;
      } else {
        result[function_ids.top()] += timestamp - current_time + 1;
        function_ids.pop();
        current_time = timestamp + 1;
      }
    }
    return result;
  }
};
