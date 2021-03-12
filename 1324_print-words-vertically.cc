#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;
        istringstream iss(s);
        string word;
        int longest_length = 0;
        // Process for each word
        for (int cnt = 0; iss >> word; ++cnt) {
            // Expand vector if needed
            while (word.size() > longest_length) {
                ans.push_back(string(cnt, ' '));
                ++longest_length;
            }
            // Put the word vertically
            for (int i = 0; i < word.size(); ++i) {
                ans[i].push_back(word[i]);
            }
            // Add a space if there is a row left
            for (int i = word.size(); i < ans.size(); ++i) {
                ans[i].push_back(' ');
            }
        }
        // Remove trailing spaces
        for (auto &x : ans) {
            while (x.back() == ' ') {
                x.pop_back();
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
