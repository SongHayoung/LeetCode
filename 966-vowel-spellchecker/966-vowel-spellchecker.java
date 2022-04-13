class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> wordSet = new HashSet<>();
        Map<String, String> vowelMap = new HashMap<>();
        Map<String, String> wordMap = new HashMap<>();
        for(String word : wordlist) {
            wordSet.add(word);
            wordMap.putIfAbsent(word.toLowerCase(), word);
            vowelMap.putIfAbsent(convert(word.toLowerCase()), word);
        }

        String[] res = new String[queries.length];
        for(int idx = 0; idx < queries.length; idx++) {
            if(wordSet.contains(queries[idx])) {
                res[idx] = queries[idx];
            } else if(wordMap.containsKey(queries[idx].toLowerCase())) {
                res[idx] = wordMap.get(queries[idx].toLowerCase());
            } else if(vowelMap.containsKey(convert(queries[idx].toLowerCase()))) {
                res[idx] = vowelMap.get(convert(queries[idx].toLowerCase()));
            } else {
                res[idx] = "";
            }
        }

        return res;
    }

    private String convert(String s) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    sb.append("*"); break;
                default:
                    sb.append(s.charAt(i)); break;
            }
        }
        return sb.toString();
    }
}