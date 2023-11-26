class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int p = 0;
        for(auto& r : mat) {
            deque<int> dq;
            for(int i = 0; i < r.size(); i++) dq.push_back(r[i]);
            int mv = k % r.size();
            if(p % 2 == 0) {
                while(mv--) {
                    dq.push_back(dq.front()); dq.pop_front();
                }
            } else {
                while(mv--) {
                    dq.push_front(dq.back()); dq.pop_back();
                }
            }
            
            for(int i = 0; i < dq.size(); i++) {
                if(dq[i] != r[i]) return false;
            }
            p += 1;
        }
        
        
        return true;
    }
};