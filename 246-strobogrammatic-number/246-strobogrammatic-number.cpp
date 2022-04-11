class Solution {
public:
    bool isStrobogrammatic(string num) {
        int start = 0, end = num.size() - 1, mid = num.size() / 2;
        for(; start <= mid; start++, end--) {
            switch (num[start]) {
                case '0' :
                case '1' :
                case '8' :
                    if(num[end] != num[start]) return false;
                    break;
                case '6' :
                    if(num[end] != '9') return false;
                    break;
                case '9' :
                    if(num[end] != '6') return false;
                    break;
                default:
                    return false;
            }
        }
        return true;
    }
};