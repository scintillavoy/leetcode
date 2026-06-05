#include <cctype>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string reformatDate(string date) {
    istringstream iss(date);
    string day;
    string month;
    string year;
    iss >> day >> month >> year;
    string reformatted = year;
    reformatted.push_back('-');
    reformatted += month_to_num[month];
    reformatted.push_back('-');
    if (isdigit(day[1])) {
      reformatted += day.substr(0, 2);
    } else {
      reformatted.push_back('0');
      reformatted.push_back(day[0]);
    }
    return reformatted;
  }

 private:
  unordered_map<string, string> month_to_num = {
      {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
      {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
      {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"},
  };
};
