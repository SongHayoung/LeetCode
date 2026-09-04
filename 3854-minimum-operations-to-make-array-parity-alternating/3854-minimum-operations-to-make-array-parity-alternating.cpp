
class Solution {
    vector<int> helper(vector<int> A, int op) {
        vector<int> changed, nchanged;
        for(auto& n : A) {
            if((n & 1) == op) nchanged.push_back(n);
            else changed.push_back(n);
            op = !op;
        }
        int cnt = changed.size();
        sort(begin(changed), end(changed));
        sort(begin(nchanged), end(nchanged));
        int mi = INT_MIN, ma = INT_MAX;
        if(changed.empty()) {
            return {cnt, nchanged.back() - nchanged.front()};
        }
        if(nchanged.empty()) {
            return {cnt, abs(changed.back() - 1 - (changed.front() + 1))};
        }
        if(changed.size() == 1) {
          if(nchanged.size() == 1) {
              return {cnt, min(abs(nchanged[0] - (changed[0] - 1)), abs(nchanged[0] - (changed[0] + 1)))};
          }
          int l = nchanged.front(), r = nchanged.back();
          vector<int> C{changed[0] + 1, changed[0] - 1};
          int diff = INT_MAX;
          for(auto& c : C) {
              diff = min(diff, max(r,c) - min(l,c));
          }
          return {cnt, diff};
        }
        vector<int> base{nchanged[0]};
        if(nchanged.size() != 1) base.push_back(nchanged.back());
        int diff = INT_MAX;
        vector<int> ops{-1,1};
        for(auto& op1 : ops) {
            for(auto& op2 : ops) {
                vector<int> now = base;
                now.push_back(changed[0] + op1);
                if(changed.size() != 1) now.push_back(changed.back() + op2);
                sort(begin(now), end(now));
                diff = min(diff, now.back() - now.front());
            }
        }
        return {cnt,diff};
    }
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        return min(helper(nums,0), helper(nums,1));
    }
};