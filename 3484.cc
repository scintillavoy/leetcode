#include <cctype>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Spreadsheet {
 public:
  Spreadsheet(int rows) {
    sheet = vector<vector<int>>(26, vector<int>(rows + 1));
  }

  void setCell(string cell, int value) {
    auto [x, y] = cellReferenceToIndices(cell);
    sheet[x][y] = value;
  }

  void resetCell(string cell) { setCell(cell, 0); }

  int getValue(string formula) {
    int start = 1, end = 1;
    while (formula[end] != '+') {
      ++end;
    }
    string left_operand = formula.substr(start, end - start);
    string right_operand = formula.substr(end + 1);
    int value = 0;
    if (isalpha(left_operand[0])) {
      auto [x, y] = cellReferenceToIndices(left_operand);
      value += sheet[x][y];
    } else {
      value += stoi(left_operand);
    }
    if (isalpha(right_operand[0])) {
      auto [x, y] = cellReferenceToIndices(right_operand);
      value += sheet[x][y];
    } else {
      value += stoi(right_operand);
    }
    return value;
  }

 private:
  vector<vector<int>> sheet;

  pair<int, int> cellReferenceToIndices(string &cell) {
    return {cell[0] - 'A', stoi(cell.substr(1))};
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
