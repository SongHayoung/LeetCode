class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int now = 0;
            if(k > 0) {
                for(int j = 0; j < k; j++) now = (now + code[(1+i+j)%n]);
            } else if(k < 0) {
                for(int j = 0; j < -k; j++) now = (now + code[(i-j-1+n)%n]);
            }
            res.push_back(now);
        }
        return res;
    }
};