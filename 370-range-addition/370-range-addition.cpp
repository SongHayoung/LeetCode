class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        int sum(0);
        for(auto& u : updates) {
            res[u[0]] += u[2];
            if(u[1] + 1 < length)
                res[u[1] + 1] -= u[2];
        }

        for (auto& r: res) {
            sum += r;
            r = sum;
        }
        return res;

    }
};