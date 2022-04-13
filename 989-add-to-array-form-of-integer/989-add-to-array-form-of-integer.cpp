class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int i = num.size() - 1; i >= 0 and k; i--) {
            int n = k % 10;
            k/=10;
            num[i] += n;
            if(num[i] >= 10) {
                num[i] -= 10;
                k += 1;
            }
        }
        if(k == 0) return num;
        
        string n = to_string(k);
        vector<int> res;
        for(auto ch : n)
            res.push_back(ch&0b1111);
        for(auto digit : num)
            res.push_back(digit);
        return res;
    }
};