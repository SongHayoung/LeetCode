class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int any = 0, at = 0;
        for(auto m : moves) {
            if(m == 'L') at += 1;
            else if(m == 'R') at -= 1;
            else any += 1;
        }
        int res = at;
        res = max(res, abs(at - any));
        res = max(res, abs(at + any));
        return res;
    }
};