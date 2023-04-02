class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int res = 0, a = 0, b = 0;
        priority_queue<int> qa, qb;
        for(int i = 0; i < reward1.size(); i++) {
            if(reward1[i] > reward2[i]) {
                a += 1;
                res += reward1[i];
                qa.push(reward2[i] - reward1[i]);
            } else {
                b += 1;
                res += reward2[i];
                qb.push(reward1[i] - reward2[i]);
            }
        }
        if(a == k) return res;
        if(a < k) {
            while(a < k) {
                a += 1;
                res += qb.top(); qb.pop();
            }
        }
        if(a > k) {
            while(a > k) {
                a -= 1;
                res += qa.top(); qa.pop();
            }
        }
        return res;
    }
};