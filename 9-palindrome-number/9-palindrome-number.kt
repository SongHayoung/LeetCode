class Solution {
    fun isPalindrome(x: Int): Boolean {
        if(x < 0) return false
        var o = x;
        var r = 0;
        while(o > 0) {
            r = r * 10 + o % 10;
            o /= 10;
        }
        return x == r
    }
}