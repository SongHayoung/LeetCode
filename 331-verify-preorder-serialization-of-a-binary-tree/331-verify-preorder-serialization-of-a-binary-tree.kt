class Solution {
    fun isValidSerialization(preorder: String): Boolean {
        val tokens = preorder.split(',');
        if(tokens[0] == "#") return tokens.size == 1;
        val cntSt = mutableListOf(0);
        for(i in 1 until tokens.size) {
            if(cntSt.isEmpty()) return false;
            cntSt[cntSt.size - 1] += 1;
            if(cntSt[cntSt.size - 1] > 2) return false;
            if(tokens[i]=="#") {
                while(!cntSt.isEmpty() && cntSt[cntSt.size-1] == 2)
                    cntSt.removeAt(cntSt.size-1);
            } else {
                cntSt.add(0);
            }
        }
        return cntSt.isEmpty();
    }
}