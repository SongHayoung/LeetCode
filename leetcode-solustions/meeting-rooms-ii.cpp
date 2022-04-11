class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int res = 1;
        priority_queue<int, vector<int>, greater<>> q;
        for(auto it = arr.begin(); it != end(arr);) {
            while(!q.empty() && q.top() <= it->front()) q.pop();
            int time = it->front();
            while(it != end(arr) && it->front() == time) {
                q.push(it->back());
                it = next(it);
            }
            res = max(res, (int)q.size());
        }
        return res;
    }
};
