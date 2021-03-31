class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(!arr[start]) return true;

        int sz = arr.size();
        vector<bool> v(sz, false);
        queue<int> q;
        q.push(start);
        v[start] = true;
        while(!q.empty()) {
            int pos = q.front();
            q.pop();
            int left = pos - arr[pos], right = pos + arr[pos];
            if(left >= 0 && !v[left]) {
                if(!arr[left]) return true;
                v[left] = true;
                q.push(left);
            }
            if(right < sz && !v[right]) {
                if(!arr[right]) return true;
                v[right] = true;
                q.push(right);
            }
        }
        return false;
    }
};
