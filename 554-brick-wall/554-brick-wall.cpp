class Solution {
public:
    int leastBricks(vector<vector<int>>& A) {
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
        priority_queue<int, vector<int>, greater<int>> fin;
        int res = A.size(), inc = 0, now = 0, sum = 0;
        for(auto& row : A) {
            int psum = 0;
            for(auto& col : row) {
                q.push({psum,psum+col});
                psum += col;
            }
            sum = psum;
        }
        while(!q.empty()) {
            int mi = q.top().first;
            now = mi;
            if(!fin.empty()) mi = min(mi, fin.top());
            while(!fin.empty() and fin.top() == mi) {
                inc--;
                fin.pop();
            }
            if(now != 0 and now != sum) res = min(res, inc);
            while(!q.empty() and q.top().first == mi) {
                fin.push(q.top().second); q.pop();
                inc++;
            }
        }
        while(!fin.empty()) {
            int f = fin.top();
            now = f;
            while(!fin.empty() and fin.top() == f) {
                inc--;
                fin.pop();
            }
            if(now != 0 and now != sum) res = min(res,inc);
        }
        return res;
    }
};