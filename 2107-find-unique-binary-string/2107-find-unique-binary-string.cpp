class Solution {
    string build(int x, int n) {
        string res(n,'0');
        int p = n-1;
        while(x) {
            if(x & 1) res[p] = '1';
            p--;
            x /= 2;
        }
        return res;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> us(begin(nums), end(nums));
        for(int i = 0; i <= nums.size(); i++) {
            string x = build(i,nums.size());
            if(!us.count(x)) return x;
        }
        return "";
    }
};