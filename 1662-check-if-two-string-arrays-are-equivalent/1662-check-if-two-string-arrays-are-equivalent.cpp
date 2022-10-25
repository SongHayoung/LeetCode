class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& A, vector<string>& B) {
        while(A.size() and B.size()) {
            if(A.back().back() != B.back().back()) return false;
            A.back().pop_back();
            B.back().pop_back();
            if(A.back().empty()) A.pop_back();
            if(B.back().empty()) B.pop_back();
        }
        return A.empty() and B.empty();
    }
};