#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    vector<vector<int>> result(m, vector<int>(n, -1));
    int x = 0, y = -1;
    while (head != nullptr) {
      int x2 = x + dx[direction];
      int y2 = y + dy[direction];
      if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || result[x2][y2] != -1) {
        direction = (direction + 1) % 4;
      }
      x += dx[direction];
      y += dy[direction];
      result[x][y] = head->val;
      head = head->next;
    }
    return result;
  }

 private:
  const int dx[4] = {0, 1, 0, -1};
  const int dy[4] = {1, 0, -1, 0};

  int direction = 0;
};
