class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(!rowIndex) return {1};
        vector<int> res = {1,1}, prev;
        while(--rowIndex) {
            swap(prev,res);
            res.clear();
            res.push_back(1);
            for(int i = 0; i < prev.size() - 1; i++) {
                res.push_back(prev[i] + prev[i+1]);
            }
            res.push_back(1);
        }
        return res;
    }
};