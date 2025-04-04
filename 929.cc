#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> email_addresses;
    for (const auto& email : emails) {
      int index = 0;
      string canonicalized_email;
      while (index < email.size()) {
        switch (email[index]) {
          case '.':
            break;
          case '+':
            while (email[index] != '@') {
              ++index;
            }
            // Fall-through on purpose.
          case '@':
            canonicalized_email.push_back('@');
            ++index;
            while (index < email.size()) {
              canonicalized_email.push_back(email[index]);
              ++index;
            }
            break;
          default:
            canonicalized_email.push_back(email[index]);
        }
        ++index;
      }
      email_addresses.insert(canonicalized_email);
    }
    return email_addresses.size();
  }
};
