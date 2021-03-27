class Solution {
    private static final String DOT = ".";
    private static final String NONE = "";
    private static final String DOUBLE_DOT = "..";
    private static final String SLASH = "/";

    public String simplifyPath(String path) {
        String[] tokens = path.split(SLASH);
        List<String> directoryList = new LinkedList<>();
        for(String token : tokens) {
            if(DOT.equals(token) || NONE.equals(token)) {
                continue;
            } else if(DOUBLE_DOT.equals(token)) {
                if(!directoryList.isEmpty()) {
                    directoryList.remove(directoryList.size() - 1);
                }
            } else {
                directoryList.add(token);
            }
        }

        return SLASH + directoryList.stream().collect(Collectors.joining(SLASH));
    }
}
