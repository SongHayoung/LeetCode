class Solution {
    long long b10(string s) {
        long long res = 0;
        for(int i = 0; i < 2; i++) {
            long long now = 0;
            if(isdigit(s[i])) now = s[i] - '0';
            else now = s[i] - 'a' + 10;
            res = (res + now * (i ? 1 : 16));
        }
        return res;
    }
    long long helper(string A, string B) {
        long long a = b10(A), b = b10(B);
        return (a - b) * (a - b);
    }
public:
    string similarRGB(string color) {
        long long mi = -1e18;
        string A = color.substr(1,2), B = color.substr(3,2), C = color.substr(5,2);
        string res = "";
        vector<char> b16{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        for(int i = 0; i < 16; i++) {
            for(int j = 0; j < 16; j++) {
                for(int k = 0; k < 16; k++) {
                    long long diff = -helper(A, string(2,b16[i])) - 
                        helper(B, string(2,b16[j])) - 
                        helper(C, string(2,b16[k]));
                    
                    if(diff > mi) {
                        res = "#" + string(2,b16[i]) + string(2,b16[j]) + string(2,b16[k]);
                        mi = diff;
                    }
                }
            }
        }
        
        
        return res;
    }
};