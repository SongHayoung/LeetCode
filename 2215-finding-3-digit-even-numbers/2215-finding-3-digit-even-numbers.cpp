class Solution {
    void helper(vector<int>& freq, vector<int>& res, int now) {
        if(100 <= now and now <= 999) {
            if(now % 2 == 0) res.push_back(now);
            return;
        }
        for(int i = !now; i < 10; i++) {
            if(!freq[i]) continue;
            freq[i]--;
            helper(freq,res,now * 10 + i);
            freq[i]++;
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10), res;
        for(auto& d : digits) freq[d]++;
        helper(freq,res,0);
        return res;
    }
};