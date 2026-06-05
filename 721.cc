#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    parents = vector<int>(n);
    for (int i = 0; i < parents.size(); ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(n);

    unordered_map<string, int> email_to_id;
    for (int i = 0; i < accounts.size(); ++i) {
      for (int j = 1; j < accounts[i].size(); ++j) {
        if (email_to_id.contains(accounts[i][j])) {
          union_set(email_to_id[accounts[i][j]], i);
        } else {
          email_to_id[accounts[i][j]] = i;
        }
      }
    }

    unordered_map<int, vector<string>> id_to_emails;
    for (const auto& [email, id] : email_to_id) {
      id_to_emails[find_set(id)].push_back(email);
    }

    vector<vector<string>> merged_accounts;
    for (const auto& [id, emails] : id_to_emails) {
      merged_accounts.push_back({accounts[id][0]});
      for (const auto& email : emails) {
        merged_accounts.back().push_back(email);
      }
      sort(merged_accounts.back().begin() + 1, merged_accounts.back().end());
    }

    return merged_accounts;
  }

 private:
  vector<int> parents;
  vector<int> ranks;

  int find_set(int x) {
    if (parents[x] != x) {
      parents[x] = find_set(parents[x]);
    }
    return parents[x];
  }

  void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return;
    }
    if (ranks[x] > ranks[y]) {
      swap(x, y);
    } else if (ranks[x] == ranks[y]) {
      ++ranks[y];
    }
    parents[x] = y;
  }
};
