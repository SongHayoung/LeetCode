class Solution {
    fun areSentencesSimilar(sentence1: String, sentence2: String): Boolean {
        val token1 = sentence1.split(' ').toMutableList()
        val token2 = sentence2.split(' ').toMutableList()

        return if(token1.size > token2.size) isSimilar(token2, token1) else isSimilar(token1, token2)
    }

    private fun isSimilar(token1: MutableList<String>, token2: MutableList<String>): Boolean {
        while(token1.isNotEmpty() && token1.last() == token2.last()) {
            token1.removeAt(token1.lastIndex)
            token2.removeAt(token2.lastIndex)
        }
        
        while(token1.isNotEmpty() && token1.first() == token2.first()) {
            token1.removeAt(0)
            token2.removeAt(0)
        }

        return token1.isEmpty()
    }
}