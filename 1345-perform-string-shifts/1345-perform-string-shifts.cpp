class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int len = s.length(), mv = 0;
        for(auto shi : shift) {
            if(shi[0] == 0) mv -= shi[1];
            else mv += shi[1];
        }
        mv %= len;
        if(mv < 0) mv += len;
        
        return s.substr(len-mv) + s.substr(0, len - mv);
    }
};