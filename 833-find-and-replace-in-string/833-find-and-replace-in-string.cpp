class Solution {
    int fenwick[1001]{0,};
    void update(int index, int value) {
        index += 1;
        while(index < 1002) {
            fenwick[index] += value;
            index += (index & -index);
        }
    }
    int qry(int index) {
        index += 1; //zero prevention
        int res = 0;
        while(index > 0) {
            res += fenwick[index];
            index -= (index & -index);
        }
        return res;
    }
    
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        for(int i = 0; i < n; i++) {
            int index = indices[i] + qry(indices[i]);
            bool check = index + sources[i].length() <= s.length();
            for(int j = index; j < index + sources[i].length() and check; j++) {
                if(s[j] != sources[i][j-index]) check = false;
            }
            if(check) {
                s.replace(index, sources[i].length(), targets[i]);
                update(indices[i], targets[i].length() - sources[i].length());
            }
        }
        return s;
    }
};