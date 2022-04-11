class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length())
            return addBinary(b,a);
        int append = 0, i = a.length() - 1, j = b.length() - 1;
        while(i >= 0 or j >= 0) {
            int A = i >= 0 ? a[i] & 0b1111 : 0;
            int B = j >= 0 ? b[j] & 0b1111 : 0;
            int sum = A + B + append;
            append = (sum >= 2);
            if(sum >= 2) sum -= 2;
            a[i] = sum | 0b110000;
            
            i--,j--;
        }
        return append ? '1' + a : a;
    }
};