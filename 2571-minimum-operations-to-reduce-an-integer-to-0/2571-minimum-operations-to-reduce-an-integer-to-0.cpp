
class Solution {
public:
    int minOperations(int n) {
        vector<int> bit;
        while(n) {
            bit.push_back(n%2);
            n /= 2;
        }
        bit.push_back(0);
        bit.push_back(0);
        int res = 0;
        for(int i = 0, cnt = 0; i < bit.size() - 1; i++) {
            if(bit[i] == 1) {
                if(cnt == 0) res += 1;
                cnt += 1;
            } else if(bit[i] == 0) {
                if(cnt == 1) cnt = 0;
                else if(cnt > 1) {
                    res += 1;
                    if(bit[i+1] == 0) cnt = 0;
                }
            }
        }
        return res;
    }
};
