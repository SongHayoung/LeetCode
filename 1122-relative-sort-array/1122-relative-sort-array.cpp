class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> ord;
        for(int i = 0; i < B.size(); i++) ord[B[i]] = i;
        sort(begin(A), end(A), [&](int i, int j) {
            if(ord.count(i) and ord.count(j)) return ord[i] < ord[j];
            if(!ord.count(i) and !ord.count(j)) return i < j;
            return (bool)(ord.count(i));
        });
        return A;
    }
};