class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int res = 0, n = startTime.size();
        multiset<int> ms;
        for(int i = 0; i < n; i++) {
            int st = i ? endTime[i-1] : 0;
            int ed = i + 1 == n ? eventTime : startTime[i+1];
            if(i) {
                ms.insert(startTime[i] - endTime[i-1]);
                if(i + 1 == n) ms.insert(eventTime - endTime[i]);
            } else ms.insert(startTime[i]);
            res = max(res, ed - st - (endTime[i] - startTime[i]));
        }
        for(int i = 0; i < n; i++) {
            int le = i ? startTime[i] - endTime[i-1] : startTime[i];
            int ri = i + 1 == n? eventTime - endTime[i] : startTime[i+1] - endTime[i];
            ms.erase(ms.find(le));
            ms.erase(ms.find(ri));
            
            int size = endTime[i] - startTime[i];
            if(ms.size() and *prev(end(ms)) >= size) {
                int st = i ? endTime[i-1] : 0;
                int ed = i + 1 == n ? eventTime : startTime[i+1];
                res = max(res, ed - st);
            }
            
            ms.insert(le);
            ms.insert(ri);
        }
        return res;
    }
};