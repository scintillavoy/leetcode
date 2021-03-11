#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        vector<int> ints{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> romans{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        for (int i = ints.size() - 1; i >= 0; --i) {
            while (num >= ints[i]) {
                num -= ints[i];
                ans += romans[i];
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
