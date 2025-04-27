class Solution {
    fun findCommonResponse(responses: List<List<String>>): String {
        return responses
            .map { it.distinct() }
            .flatten()
            .groupingBy { it }
            .eachCount()
            .entries
            .sortedWith(compareByDescending<Map.Entry<String, Int>> { it.value }
                .thenBy { it.key })
            .firstOrNull()?.key ?: ""
    }
}