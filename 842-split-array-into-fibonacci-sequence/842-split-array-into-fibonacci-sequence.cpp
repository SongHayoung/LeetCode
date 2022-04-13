class Solution {
    bool verify(vector<int>& fibo) {
        int sz = fibo.size();
        return 1ll * fibo[sz-1] == 1ll * fibo[sz-2] + 1ll * fibo[sz-3];
    }
    bool helper(string& num, int p, vector<int>& fibo) {
        if(fibo.size() >= 3) 
            if(!verify(fibo)) return false;
        if(p == num.length()) return fibo.size() >= 3;
        long n = 0;
        for(int i = p; i < num.length(); i++) {
            if(i != p and n == 0) return false;
            
            n = n * 10 + (num[i] & 0b1111);
            if(n > INT_MAX) return false;
            
            fibo.push_back(n);
            if(helper(num,i+1,fibo)) return true;
            fibo.pop_back();
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> res;
        if(helper(num,0,res)) return res;
        return {};
    }
};