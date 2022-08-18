class Solution {
public:
    char findKthBit(int n, int k) {
        string st = "0";
        int p = 0;
        while(st.size() < k) {
            if(p == st.size() - 1) st.push_back('1');
            else if(p < 0) p = st.size() - 1;
            else {
                if(st[p--] == '0') st.push_back('1');
                else st.push_back('0');
            }
        }
        return st[k-1];
    }
};