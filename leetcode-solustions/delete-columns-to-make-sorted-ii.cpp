class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<bool> cmp(strs.size(), false);
        int res = 0, len = strs[0].length();
        for(int i = 0; i < len; ++i) {
            int flag = 0;
            list<int> canPass;
            for(int j = 0; j < strs.size() - 1; j++) {
                if(cmp[j]) continue;
                if(strs[j][i] > strs[j + 1][i]) {
                    flag = 1;
                    res++;
                    break;
                } else if(strs[j][i] == strs[j + 1][i]) {
                    for(int k = i + 1; k < len; ++k) {
                        if(strs[j][k] > strs[j + 1][k]) {
                            flag = 2;
                            break;
                        }
                    }
                } else {
                    canPass.push_back(j);
                }
            }
            if(!flag) {
                break;
            } else if(flag == 2) {
                for(auto& pos : canPass)
                    cmp[pos] = true;
            }
        }

        return res;
    }
};
