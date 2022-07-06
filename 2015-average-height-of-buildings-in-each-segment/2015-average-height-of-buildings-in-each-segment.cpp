class Solution {
    void compress(vector<vector<int>>& res) {
        while(res.size() >= 2 and res[res.size() - 1][2] == res[res.size() - 2][2] and res[res.size() - 1][0] == res[res.size() - 2][1]) {
            res[res.size() - 2][1] = res[res.size() - 1][1];
            res.pop_back();
        }
    }
    
    int erase(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, int target) {
        int res = 0;
        while(!pq.empty() and pq.top().first == target) {
                res += pq.top().second;
                pq.pop();
        }
        return res;
    }
    
    int insert(vector<vector<int>>& A, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, int target) {
        int res = 0;
        while(!A.empty() and A.back()[0] == target) {
            res += A.back()[2];
            pq.push({A.back()[1], A.back()[2]});
            A.pop_back();
        }
        return res;
    }
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& A) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sum = 0, n = A.size(), last = 0, i = 0;
        vector<vector<int>> res;
        sort(rbegin(A), rend(A));
        while(!A.empty()) {
            int start = A.back()[0];
            if(!pq.empty()) start = min(start, pq.top().first);
            if(sum) res.push_back({last, start, (int)(sum / pq.size())});
            sum -= erase(pq,start);
            sum += insert(A,pq,start);
            last = start;
            compress(res);
        }
        
        while(!pq.empty()) {
            auto [e, _] = pq.top();
            res.push_back({last, e, (int)(sum / pq.size())});
            
            sum -= erase(pq,e);
            
            compress(res);
            last = e;
        }
        return res;
    }
};