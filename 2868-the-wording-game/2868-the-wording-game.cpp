class Solution {
public:
    bool canAliceWin(vector<string>& a, vector<string>& b) {
        int i = 0, j = 0;
        while(i < a.size()) {
            while(j < b.size() and b[j] <= a[i]) j += 1;
            if(j == b.size() or b[j][0] > a[i][0] + 1) return true;
            while(i < a.size() and a[i] <= b[j]) i += 1;
            if(i == a.size() or a[i][0] > b[j][0] + 1) return false;
        }
        return false;
    }
};