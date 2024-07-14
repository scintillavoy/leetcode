#include <algorithm>
#include <cctype>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string countOfAtoms(string formula) {
    unordered_map<string, int> atoms;
    stack<int> multipliers;
    int curr_multiplier = 1;
    string curr_number;
    string curr_atom;
    for (int i = formula.size() - 1; i >= 0; --i) {
      if (isdigit(formula[i])) {
        curr_number += formula[i];
      } else if (formula[i] == ')') {
        reverse(curr_number.begin(), curr_number.end());
        int number = curr_number.empty() ? 1 : stoi(curr_number);
        curr_multiplier *= number;
        multipliers.push(number);
        curr_number.clear();
      } else if (formula[i] == '(') {
        curr_multiplier /= multipliers.top();
        multipliers.pop();
      } else if (isupper(formula[i])) {
        curr_atom += formula[i];
        reverse(curr_atom.begin(), curr_atom.end());
        reverse(curr_number.begin(), curr_number.end());
        atoms[curr_atom] +=
            (curr_number.empty() ? 1 : stoi(curr_number)) * curr_multiplier;
        curr_atom.clear();
        curr_number.clear();
      } else if (islower(formula[i])) {
        curr_atom += formula[i];
      }
    }
    string result;
    map<string, int> sorted_atoms(atoms.cbegin(), atoms.cend());
    for (const auto &[atom, count] : sorted_atoms) {
      result += atom;
      if (count > 1) {
        result += to_string(count);
      }
    }
    return result;
  }
};
