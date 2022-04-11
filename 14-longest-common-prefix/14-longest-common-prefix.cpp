class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0, target, find = 1;
        for(; find ; index++) {
            for(target = 0; target < strs.size(); target++) {
                if(strs[target].length() == index) {find = 0; break;}
                if(strs[target][index] != strs[0][index]) {find = 0; break;}
            }
        }
        return strs[target].substr(0,index-1);
    }
};