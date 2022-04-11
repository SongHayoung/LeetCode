class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int> pq;
        int res = 0;
        int left = events.size();
        sort(events.begin(), events.end());
        auto event = events.begin();

        for(int i = 1; left; i++) {
            while(event != events.end() && event->front() <= i) {
                pq.push(-event->back());
                event++;
            }

            if(pq.empty())
                continue;

            pq.pop();
            ++res;
            --left;
            while(!pq.empty() && -pq.top() == i) {
                pq.pop();
                --left;
            }
        }

        return res;
    }
};
