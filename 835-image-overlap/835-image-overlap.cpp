class Solution {
    //o(logn)
    int count(long long n) { //get bit count
        int res = 0;
        while(n) {
            if(n&1) res++;
            n>>=1;
        }
        return res;
    }
    //o(min(m1.size()-st1, m2.size()-st2) * logn)
    int match(vector<long long>& m1, vector<long long>& m2, int st1, int st2) { //check mating bit count
        int res = 0;
        for(int i = st1, j = st2; i < m1.size() and j < m2.size(); i++,j++) {
            long long mask = m1[i] & m2[j];
            res += count(mask);
        }
        return res;
    }
    //o(2nlogn) = o(nlogn)
    int getMaxMatchCount(vector<long long>& m1, vector<long long>& m2) { //check whole bit matching count include move up and move down
        int res = match(m1, m2, 0, 0);
        for(int i = 0; i < m1.size(); i++) {
            res = max(res, match(m1,m2,i,0));
        }
        for(int i = 0; i < m2.size(); i++) {
            res = max(res, match(m1,m2,0,i));
        }
        return res;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<long long> mask;
        for(int i = 0; i < img2.size(); i++) {
            long long m = 0;
            for(int j = 0; j < img2[i].size(); j++) {
                m = (m<<1) + img2[i][j];
            }
            mask.push_back(m);
        }
        vector<long long> leftMask, rightMask;

        long long l = 0, r = 0;
        for(int i = 0; i < img1.size(); i++) {
            long long m = 0;
            for(int j = 0; j < img1[i].size(); j++) {
                m = (m<<1) + img1[i][j];
            }
            leftMask.push_back(m);
            rightMask.push_back(m);
            l |= m;
            r |= m;
        }
        int res = 0;
        for(int i = 0; i < img1[0].size() ; i++) { //o(n^2logn)
        //    if(l) { //if is there any bit in left mask
                res = max(res, getMaxMatchCount(leftMask, mask));
                l = 0;
                for(long long i = 0, marking = (1<<leftMask.size()) - 1; i < leftMask.size(); i++) { //move bit left
                    leftMask[i] = marking & (leftMask[i]<<1);
                //    l |= leftMask[i];
                }
        //    }
         //   if(r) { //if is there any bit in right mask
                res = max(res, getMaxMatchCount(rightMask, mask));
                r = 0;
                for(int i = 0; i < rightMask.size(); i++) { //move bit right
                    rightMask[i] = rightMask[i]>>1;
            //        r |= rightMask[i];
                }
          //  }
        }
        return res;
    }
};