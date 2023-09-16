class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        multimap<int,int> match;
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto x : nums) {
            if(q.size() and q.top() < x) {
                match.insert(make_pair(x, q.top()));
                q.pop();
            } else {
                auto it = match.lower_bound(x);
                if(it == begin(match)) {
                    q.push(x);
                } else {
                    --it;
                    auto [k,v] = *it;
                    match.insert(make_pair(x,k));
                    q.push(v);
                    match.erase(it);
                }
            }
        }
        return q.size();
    }
};
