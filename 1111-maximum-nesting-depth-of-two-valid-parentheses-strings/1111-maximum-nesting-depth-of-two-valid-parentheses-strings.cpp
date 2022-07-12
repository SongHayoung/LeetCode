class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int a = 0, b = 0, n = seq.length();
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            if(seq[i] == '(') {
                if(a < b) {
                    a++; res[i] = 1;
                } else b++;
            } else {
                if(a > b) {
                    a--; res[i] = 1;
                } else b--;
            }
        }
        return res;
    }
};