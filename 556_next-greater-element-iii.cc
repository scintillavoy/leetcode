#include <limits>
#include <iostream>
using namespace std;

// Simple implementation using by STL
// #include <algorithm>
// next_permutation(BidirIt first, BidirIt last);
class Solution {
public:
    int nextGreaterElement(int n) {
        int count[10] = {0,};
        int prev = numeric_limits<int>::min();
        while (n > 0) {
            if (n % 10 >= prev) {
                prev = n % 10;
                ++count[prev];
                n /= 10;
            } else {
                ++count[n % 10];
                // Swap
                for (int i = n % 10 + 1; i <= 9; ++i) {
                    if (count[i] > 0) {
                        n = n / 10 * 10 + i;
                        --count[i];
                        break;
                    }
                }
                // Instead of this, reversing the digits after swap is sufficient
                for (int i = 0; i <= 9; ++i) {
                    while (count[i] > 0) {
                        if (n > (numeric_limits<int>::max() - i) / 10) {
                            return -1;
                        }
                        n = n * 10 + i;
                        --count[i];
                    }
                }
                return n;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.nextGreaterElement(n) << endl;
    return 0;
}
