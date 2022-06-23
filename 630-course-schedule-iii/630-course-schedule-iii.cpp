class Solution {
public:
    int scheduleCourse(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int time = 0;
        for(auto& a : A) {
            auto d = a[0], l = a[1];
            time += d;
            pq.push(d);
            if(time > l) {
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
