class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        Map<Character, Integer> bMap = new HashMap<>();
        for (String b : B) {
            bMap = Stream.concat(bMap.entrySet().stream(),
                    b.chars().boxed().collect(Collectors.toMap(k -> (char) k.intValue(), v -> 1, Integer::sum))
                            .entrySet().stream())
                    .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, (v1, v2) -> v1 > v2 ? v1 : v2, HashMap::new));
        }

        Map<Character, Integer> finalBMap = bMap;
        return Arrays.asList(A).parallelStream().filter(
                a -> {
                    Map<Character, Integer> aMap = a.chars().boxed().collect(Collectors.toMap(k -> (char) k.intValue(), v -> 1, Integer::sum));

                    for(Map.Entry<Character, Integer> entry : finalBMap.entrySet()) {
                        if(aMap.getOrDefault(entry.getKey(), 0) < entry.getValue())
                            return false;
                    }
                    return true;
                }
        ).collect(Collectors.toList());
    }
}
