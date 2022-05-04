class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> task;
        int gain = 0, res = 0;
        sort(begin(worker), end(worker));
        
        for(int i = 0; i < profit.size(); i++)
            task.push({difficulty[i], profit[i]});
        
        for(auto& w : worker) {
            while(!task.empty() and task.top().first <= w) {
                gain = max(gain, task.top().second);
                task.pop();
            }
            res += gain;
        }
        return res;
    }
};