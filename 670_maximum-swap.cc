#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string num_str(to_string(num));
        int count[10] = {0,};
        for (const auto &x : num_str) {
            ++count[x-'0'];
        }
        int curr = 0;
        for (int i = 9; i >= 0; --i) {
            while (count[i] > 0) {
                if (num_str[curr]-'0' == i) {
                    --count[i];
                    ++curr;
                } else {
                    for (auto it = num_str.rbegin(); it != num_str.rend(); ++it) {
                        if (*it-'0' == i) {
                            swap(num_str[curr], *it);
                            return stoi(num_str);
                        }
                    }
                }
            }
        }
        return num;
    }
};

int main() {
    return 0;
}
