String[] domainType(String[] domains) {

    String[] res = new String[domains.length];
    
    HashMap<String, String> labels = new HashMap<>(){{
        put("com", "commercial");
        put("info", "information");
        put("org", "organization");
        put("net", "network");
    }};
    
    for(int i = 0; i < domains.length; i++){
        String[] temp = domains[i].split("\\.");
        res[i] = labels.get(temp[temp.length -1]);
    }
    
    return res;
}
