class Solution {
public:
  int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int> pq;
        for (int b : blocks) pq.push(-b);
        while (pq.size() > 1) {
            int a = -pq.top(); pq.pop();
            int b = -pq.top(); pq.pop();
            pq.push(-(split + b));
        }
        return -pq.top();
    }
};