
class Solution {
    bool ok(int x, int y) {
        string s1 = to_string(x), s2 = to_string(y);
        if(s1.length() > s2.length()) swap(s1,s2);
        for(int i = 0; i < s2.length(); i++) {
            for(int j = i; j < s2.length(); j++) {
                swap(s2[i], s2[j]);
                if(stoi(s1) == stoi(s2)) return true;
                swap(s2[i], s2[j]);
            }
        }
        return false;
    }
public:
    int countPairs(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(ok(nums[i], nums[j])) res++;
            }
        }
        return res;
    }
};