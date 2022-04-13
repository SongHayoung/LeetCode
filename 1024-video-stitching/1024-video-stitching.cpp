class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](vector<int>& v1, vector<int>& v2) {
            if(v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
        });
        if(clips[0][0] != 0) return -1;
        priority_queue<int> pq;
        int res = 1;
        int e = clips[0][1];
        for(int i = 1; i < clips.size() and e < time; i++) {
            if(clips[i][0] <= e)
                pq.push(clips[i][1]);
            else {
                if(pq.empty() or pq.top() < clips[i][0]) return -1;
                e = pq.top();
                res++;
                pq.push(clips[i][1]);
            }
        }
        if(e >= time) return res;
        if(pq.top() >= time) return res + 1;
        return -1;
    }
};