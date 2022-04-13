class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int l = 0, r = 0, f1 = -1, f2 = -1, f1c = 0, f2c = 0;
        
        while(r < fruits.size()) {
            if(f1 == fruits[r]) {res = max(res, r - l + 1);
                r++; f1c++;
            } else if(f2 == fruits[r]) {res = max(res, r - l + 1);
                r++; f2c++;
            } else {
                while(f1c != 0 and f2c != 0) {
                    if(f1 == fruits[l]) {
                        l++; f1c--;
                    } else {
                        l++; f2c--;
                    }
                }
                if(f1c == 0) {
                    f1c = 1;
                    f1 = fruits[r];
                } else {
                    f2c = 1;
                    f2 = fruits[r];
                }
                res = max(res, r - l + 1);
                r++;
                
            }
            
        }
        return res;
    }
};