class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        queue<vector<int>> q;
        unordered_set<string> vis;
        auto push = [&](vector<int>& A) {
            string key = "";
            for(auto& a : A) key += to_string(a) + "#";
            if(!vis.count(key)) {
                vis.insert(key);
                q.push(A);
            }
        };
        push(nums1);
        int res = 0, n = nums1.size();
        auto build = [](int cut, int until, int append, vector<int>& A) {
            queue<int> q1, q2;
            for(int i = 0; i < A.size(); i++) {
                if(cut <= i and i <= until) q2.push(A[i]);
                else q1.push(A[i]);
            }
            vector<int> res;
            while(append--) {
                res.push_back(q1.front()); q1.pop();
            }
            while(q2.size()) {
                res.push_back(q2.front()); q2.pop();
            }
            while(q1.size()) {
                res.push_back(q1.front()); q1.pop();
            }
            return res;
        };
        while(q.size()) {
            int qsz = q.size();
            while(qsz--) {
                auto A = q.front(); q.pop();
                for(int cut = 0; cut < n; cut++) {
                    for(int until = cut; until < n; until++) {
                        for(int append = 0; append < n - (until - cut + 1); append++) {
                            auto B = build(cut,until,append,A);
                            if(B == nums2) return res + 1;
                            push(B);
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
