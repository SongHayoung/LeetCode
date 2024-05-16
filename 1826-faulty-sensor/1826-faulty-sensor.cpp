class Solution {
public:
    int badSensor(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < a.size() - 1; i++) {
            if(a[i] == b[i]) continue;
            int res = 3;
            for(int x = i + 1, y = i; x < a.size() and y < b.size(); x++,y++) {
                if(a[x] != b[y]) {
                    res ^= 2;
                    break;
                }
            }
            for(int x = i, y = i+1; x < a.size() and y < b.size(); x++,y++) {
                if(a[x] != b[y]) {
                    res ^= 1;
                    break;
                }
            }
            
            return res == 0 or res == 3 ? -1 : res;
        }
        return -1;
    }
};