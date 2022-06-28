class Solution {
    pair<int, int> parse(string& s) {
        int i = 0, n = s.length();
        int a = 0, b = 0;
        int signa = 1, signb = 1;
        if(s[0] == '-') {
            signa = -1, i = 1;
        }
        
        while(i < n and s[i] != '+') {
            a = a * 10 + (s[i++] & 0b1111);
        }
        i++;
        if(s[i] == '-') {
            signb = -1, i+=1;
        }
        while(i < n and s[i] != 'i') {
            b = b * 10 + (s[i++] & 0b1111);
        }
        
        return {signa*a,signb*b};
    }
public:
    string complexNumberMultiply(string A, string B) {
        auto [aa, ab] = parse(A);
        auto [ba, bb] = parse(B);
        auto front = aa * ba - ab * bb;
        auto back = aa * bb + ba * ab;
        return to_string(front) + "+" + to_string(back) + "i";
    }
};