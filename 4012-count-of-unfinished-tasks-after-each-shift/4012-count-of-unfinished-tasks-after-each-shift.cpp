class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        map<long long,int> ord{{0,tasks.size()}};
        for(long long i = 0, c = 0; i < tasks.size(); i++) {
            c += tasks[i];
            ord[c] = tasks.size() - i - 1;
        }
        vector<int> res;
        long long t = 0;
        for(auto& s : shifts) {
            t += s;
            res.push_back(prev(ord.upper_bound(t))->second);
            if(res.back() == 0) t = 0;
        }
        return res;
    }
};