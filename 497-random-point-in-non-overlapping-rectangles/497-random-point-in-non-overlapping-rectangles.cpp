class Solution {
    vector<int> sum;
    vector<vector<int>> r;
    
    int size(vector<int>& r) {
        return (r[3]-r[1]+1)*(r[2]-r[0]+1);
    }
public:
    Solution(vector<vector<int>>& rects): r(rects) {
        for(auto& r: rects) {
            sum.push_back(size(r) + (sum.empty()?0:sum.back()));
        }
    }

    vector<int> pick() {
        int rnd = rand()%sum.back();
        int pos = upper_bound(sum.begin(),sum.end(),rnd) - sum.begin();
        
        return {rand()%(r[pos][2]-r[pos][0]+1)+r[pos][0], rand()%(r[pos][3]-r[pos][1]+1)+r[pos][1]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */