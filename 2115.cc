#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findAllRecipes(vector<string>& recipes,
                                vector<vector<string>>& ingredients,
                                vector<string>& supplies) {
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> in_degrees;
    for (int i = 0; i < ingredients.size(); ++i) {
      for (const auto& ingredient : ingredients[i]) {
        graph[ingredient].push_back(recipes[i]);
        ++in_degrees[recipes[i]];
      }
    }
    queue<string> q;
    for (const auto& supply : supplies) {
      q.push(supply);
    }
    vector<string> possible_recipes;
    while (!q.empty()) {
      string curr = q.front();
      q.pop();
      for (const auto& adj : graph[curr]) {
        --in_degrees[adj];
        if (in_degrees[adj] == 0) {
          possible_recipes.push_back(adj);
          q.push(adj);
        }
      }
    }
    return possible_recipes;
  }
};
