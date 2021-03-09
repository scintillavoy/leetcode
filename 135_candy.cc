/**
 * - Solution
 * draw ratings graph
 * remember local maximum
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sol = 1;
        int last_candy = 1;
        int max_candy = 1;
        int max_idx = 0;

        for(int i = 1; i < ratings.size(); ++i) {
            if (ratings[i-1] <= ratings[i]) {       // Set the new local maximum
                if (ratings[i-1] == ratings[i]) {
                    last_candy = 0;
                }
                sol += ++last_candy;
                max_candy = last_candy;
                max_idx = i;
            } else {
                if (last_candy != 1) {              // It is safe to give 1 candy
                    ++sol;
                    last_candy = 1;
                } else {                            // Not safe; adjustments needed
                    if (max_candy <= i - max_idx) { // Increase the local maximum
                        ++sol;
                        ++max_candy;
                    }
                    sol += i - max_idx;             // Add to the previous ones
                }
            }
        }
        return sol;
    }
};

int main() {
    Solution sol;
    vector<int> ratings{8,2,6,7,4,7,4,2,1,5,7,8,4,2,1,1,8};
    cout << "The answer is: " << sol.candy(ratings) << endl;
    return 0;
}
