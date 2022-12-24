class Solution {
    int find(int u) {
        int res = 0;
        while(u) {
            res += 1;
            u /= 2;
        }
        return res - 1;
    }
    int lcs(int u, int v) {
        string U = "", V = "";
        while(u) {
            U.push_back((u & 1) + '0');
            u /= 2;
        }
        while(v) {
            V.push_back((v & 1) + '0');
            v /= 2;
        }
        int res = 0;
        while(U.length() and V.length()) {
            if(U.back() != V.back()) break;
            res *= 2;
            if(U.back() == '1') res |= 1;
            U.pop_back();
            V.pop_back();
        }
        return res;
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto& q : queries) {
            int u = q[0], v = q[1];
            res.push_back(find(u) + find(v) + 1 - 2 * find(lcs(u,v)));
        }
        return res;
    }
};