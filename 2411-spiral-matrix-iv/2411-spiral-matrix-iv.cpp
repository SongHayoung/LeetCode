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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> res(n,vector<int>(m,-1));
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        int nn = 0, mm = 0, d = 1;
        int y = 0, x = 0;
        auto ok = [&](int y, int x) {
            return nn <= y and y < n and mm <= x and x < m;
        };
        while(head) {
            res[y][x] = head->val;
            head = head->next;
            bool fl = false;
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[d], nx = x + dx[d];
                if(ok(ny,nx)) {
                    y = ny, x = nx;
                    fl = true;
                    break;
                }
                if(d == 1) {
                    nn++;
                } else if(d == 2) {
                    m--;
                } else if(d == 3) {
                    n--;
                } else mm++;
                d = (d + 1) % 4;
            }
            if(!fl) break;
        }
        
        return res;
    }
};