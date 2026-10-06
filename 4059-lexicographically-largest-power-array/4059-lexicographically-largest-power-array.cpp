class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<vector<int>> A{nums};
        vector<int> res(15);
        for(int i = 14; i >= 0; i--) {
            vector<vector<int>> B;
            bool fl = true;
            int cnt = 0;
            for(auto& a : A) {
                if(!fl) B.push_back(a);
                else {
                    vector<int> on, off;
                    for(auto& x : a) {
                        if(x & (1<<i)) on.push_back(x);
                        else off.push_back(x);
                    }
                    if(off.size()) {
                        fl = false;
                        if(on.size()) B.push_back(on);
                        B.push_back(off);
                        cnt += on.size();
                    } else {
                        B.push_back(on);
                        cnt += on.size();
                    }
                }
            }
            swap(A,B);
            res[15 - i - 1] = cnt;
        }
        return res;
    }
};