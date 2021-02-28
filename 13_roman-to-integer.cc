#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        for (string::size_type i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case 'I':
                    if (i+1 < s.size()) {
                        if (s[i+1] == 'V') {
                            answer += 4;
                            ++i;
                        } else if (s[i+1] == 'X') {
                            answer += 9;
                            ++i;
                        } else {
                            answer += 1;
                        }
                    } else {
                        answer += 1;
                    }
                    break;
                case 'V':
                    answer += 5;
                    break;
                case 'X':
                    if (i+1 < s.size()) {
                        if (s[i+1] == 'L') {
                            answer += 40;
                            ++i;
                        } else if (s[i+1] == 'C') {
                            answer += 90;
                            ++i;
                        } else {
                            answer += 10;
                        }
                    } else {
                        answer += 10;
                    }
                    break;
                case 'L':
                    answer += 50;
                    break;
                case 'C':
                    if (i+1 < s.size()) {
                        if (s[i+1] == 'D') {
                            answer += 400;
                            ++i;
                        } else if (s[i+1] == 'M') {
                            answer += 900;
                            ++i;
                        } else {
                            answer += 100;
                        }
                    } else {
                        answer += 100;
                    }
                    break;
                case 'D':
                    answer += 500;
                    break;
                case 'M':
                    answer += 1000;
                    break;
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    string s;
    while (cin >> s) {
        cout << sol.romanToInt(s) << endl;
    }    
    return 0;
}
