class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long idx = 0, res = 0, n = values.size();
        vector<bool> vis(n);
        while(0 <= idx and idx < n and !vis[idx]) {
            vis[idx] = true;
            if(instructions[idx] == "add") {
                res += values[idx++];
            } else idx += values[idx];
        }
        return res;
    }
};