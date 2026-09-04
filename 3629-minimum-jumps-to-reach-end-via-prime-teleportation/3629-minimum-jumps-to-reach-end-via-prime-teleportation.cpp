int factors[1010101];
class Solution {
public:
    int minJumps(vector<int>& nums) {
        if(factors[4] != 2) {
            for(long long i = 2; i < 1010101; i++) {
            if(factors[i]) continue;
            for(long long j = i * i; j < 1010101; j += i) factors[j] = i;
        }
        }
        
        int n = nums.size();
        vector<int> cost(n, INT_MAX);
        unordered_map<int,vector<int>> jump;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) continue;
            int x = nums[i];
            while(factors[x] != 0) {
                jump[factors[x]].push_back(i);
                int f = factors[x];
                while(x % f == 0) x /= f;
            }
            if(factors[x] == 0 and x != 1) jump[x].push_back(i);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        auto push = [&](int idx, int c) {
            if(cost[idx] > c) {
                cost[idx] = c;
                q.push({c,idx});
            }
        };
        push(0,0);
        auto prime = [&](int x) {
            return x != 1 and factors[x] == 0;
        };
        while(q.size()) {
            auto [c,idx] = q.top(); q.pop();
            if(cost[idx] != c) continue;
if(idx == n - 1) return c;
            if(idx) push(idx-1,c+1);
            if(idx + 1 < n) push(idx+1,c+1);
            if(prime(nums[idx])) {
                if(!jump.count(nums[idx])) continue;
                for(auto& nxt : jump[nums[idx]]) push(nxt, c + 1);
                jump.erase(nums[idx]);
            }
        }

        return cost.back();
    }
};