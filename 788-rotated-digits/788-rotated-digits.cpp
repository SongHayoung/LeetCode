class Solution {
    unordered_set<int> self{0,1,8};
    unordered_set<int> other{2,5,6,9};
    unordered_set<int> visit;
    int res = 0;
    
    void backTracking(int num, bool used, int& target) {
        if(visit.count(num)) return;
        if(num > target) return;
        visit.insert(num);
        if(used) {
            res++;
        }
        
        for(auto o : other) {
            backTracking(num * 10 + o, true, target);
        }
        for(auto s : self) {
            backTracking(num * 10 + s, used, target);
        }
        return;
    }
public:
    int rotatedDigits(int n) {
        backTracking(0,false,n);
        return res;
    }
};