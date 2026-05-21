#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> segments;
    string segment;
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '/') {
        process_segment(segments, segment);
        segment.clear();
        continue;
      }
      segment.push_back(path[i]);
    }
    process_segment(segments, segment);
    segment.clear();
    string simplified_path;
    for (const auto& s : segments) {
      simplified_path += "/" + s;
    }
    if (simplified_path.empty()) {
      simplified_path = "/";
    }
    return simplified_path;
  }

 private:
  void process_segment(vector<string>& segments, const string& segment) {
    if (segment.empty() || segment == ".") {
      return;
    }
    if (segment == "..") {
      if (!segments.empty()) {
        segments.pop_back();
      }
    } else {
      segments.push_back(segment);
    }
  }
};
