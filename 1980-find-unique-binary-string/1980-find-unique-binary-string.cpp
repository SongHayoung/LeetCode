class Solution {
    int toInt(string& s) {
        int res = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '1')
                res |= 1<<i;
        }
        return res;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> us;
        for(auto& n : nums) {
            us.insert(toInt(n));
        }
        int len = nums[0].length();
        for(int i = 0; ; i++) {
            if(us.count(i)) continue;
            string res(len, '0');
            for(int j = 0; j < len; j++) {
                if(i & (1<<j)) res[j] = '1';
            }
            return res;
        }
        return "-1";
    }
};