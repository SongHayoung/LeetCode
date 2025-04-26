class Solution {
public:
    long long countSubarrays(vector<int>& A, int mi, int ma) {
        deque<int> mipos, mapos, none;
        long long res = 0, n = A.size();
        for(int i = 0; i < n; i++) {
            if(A[i] == mi) mipos.push_back(i);
            if(A[i] == ma) mapos.push_back(i);
            if(A[i] < mi or A[i] > ma) none.push_back(i);
        }
        none.push_back(n);
        for(int i = 0; i < n; i++) {
            while(mipos.size() and mipos[0] < i) mipos.pop_front();
            while(mapos.size() and mapos[0] < i) mapos.pop_front();
            while(none.size() and none[0] < i) none.pop_front();
            if(mi <= A[i] and A[i] <= ma) {
                long long last = -1, nonep = none[0];
                if(mipos.size() and mapos.size()) last = max(mipos[0], mapos[0]);
                if(last == -1) continue;
                if(last < nonep) {
                    long long len = nonep - last;
                    res += len;
                }
            }
        }
        return res;
    }
};