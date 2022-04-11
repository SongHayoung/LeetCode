class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for(auto& d : data) {
            if(cnt) {
                cnt--;
                if(d>>6 != 2) return false;
            }
            else if(!(d>>7)) continue;  //case 0xxxxxxx
            else if(d>>5 == 6) cnt = 1; //case 110xxxxx
            else if(d>>4 == 14) cnt = 2;//case 1110xxxx
            else if(d>>3 == 30) cnt = 3;//case 11110xxx
            else return false;

        }
        return !cnt;
    }
};