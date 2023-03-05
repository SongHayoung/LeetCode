class Solution {
    unordered_map<int, vector<int>> jump;
    unordered_set<int> jumped;
    vector<int> dp;
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        dp = vector<int>(n, -1);
        dp[0] = 0;
        for(int i = 0; i < n; i++)
            jump[arr[i]].push_back(i);

        queue<int> q;
        q.push(0);
        while(!q.empty() and dp.back() == -1) {
            auto pos = q.front(); q.pop();
            if(!jumped.count(arr[pos])) {
                for(auto eq : jump[arr[pos]]) {
                    if(eq == pos) continue;
                    if(dp[eq] == -1) {
                        dp[eq] = dp[pos] + 1;
                        q.push(eq);
                    }
                }
                jumped.insert(arr[pos]);
            }

            if(pos > 0 and dp[pos - 1] == -1) {
                dp[pos - 1] = dp[pos] + 1;
                q.push(pos-1);
            }
            if(dp[pos + 1] == -1) {
                dp[pos + 1] = dp[pos] + 1;
                q.push(pos+1);
            }


        }

        return dp.back();
    }
};