class Solution {
    string helper(int x) {
        char ch = 'a';
        string res = "";
        while(x) {
            if(ch == 'z') return string(x, 'z') + res;
            if(x & 1) {
                res = ch + res;
            }
            x /= 2;
            ch++;
        }
        return res;
    }
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> res;
        for(auto& n : nums) res.push_back(helper(n));
        return res;
    }
};