class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> q;
        vector<int> res;
        for(auto& qry : queries) {
            q.push(abs(qry[0]) + abs(qry[1]));
            while(q.size() > k) q.pop();
            res.push_back(q.size() < k ? -1 : q.top());
        }
        return res;
    }
};