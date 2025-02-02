class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int res = 0, n = startTime.size();
        multiset<int> ms;
        for(int i = 0; i < n; i++) {
            if(i) {
                ms.insert(startTime[i] - endTime[i-1]);
                if(i + 1 == n) ms.insert(eventTime - endTime[i]);
            } else ms.insert(startTime[i]);
            
            while(ms.size() > 3) ms.erase(begin(ms));
        }
        vector<function<void()>> defers;
        
        for(int i = 0; i < n; i++) {
            int le = i ? startTime[i] - endTime[i-1] : startTime[i];
            int ri = i + 1 == n? eventTime - endTime[i] : startTime[i+1] - endTime[i];
            
            if(ms.find(le) != end(ms)) {
                ms.erase(ms.find(le));
                defers.push_back([&ms, le]() { ms.insert(le); });
            }
            if(ms.find(ri) != end(ms)) {
                ms.erase(ms.find(ri));
                defers.push_back([&ms, ri]() { ms.insert(ri); });
            }
            
            int size = endTime[i] - startTime[i];
            int st = i ? endTime[i-1] : 0;
            int ed = i + 1 == n ? eventTime : startTime[i+1];
            
            res = max(res, ed - st - (*prev(end(ms)) >= size ? 0 : size));
            
            while(defers.size()) {
                auto defer = defers.back(); defers.pop_back();
                defer();
            }
        }
        return res;
    }
};