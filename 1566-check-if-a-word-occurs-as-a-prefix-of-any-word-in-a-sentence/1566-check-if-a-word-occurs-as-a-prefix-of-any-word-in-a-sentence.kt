class Solution {
    fun isPrefixOfWord(sentence: String, searchWord: String): Int {
        val words = sentence.split(" ")
        for ((index, word) in words.withIndex()) {
            if (word.startsWith(searchWord)) {
                return index + 1
            }
        }
        return -1
    }
}