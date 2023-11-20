class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        int a = 0, b = 0, c = 0;
        int ca = 0, cb = 0, cc = 0;
        vector<int> psum{0};
        for(int i = 0; i < garbage.size(); i++) {
            if(i != garbage.size() - 1)
                psum.push_back(psum.back() + travel[i]);
            for(int j = 0; j < garbage[i].length(); j++) {
                if(garbage[i][j] == 'M') a = i, res++;
                if(garbage[i][j] == 'P') b = i, res++;
                if(garbage[i][j] == 'G') c = i, res++;
            }
        }
        res += psum[a];
        res += psum[b];
        res += psum[c];
        return res;
    }
};