int gcd(int a, int b){
    
    if(b > a){
        int temp = a;
        a = b;
        b = temp;
    }
    
    while(b != 0){
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int[] videoPart(String part, String total) {
    String[] partTime = part.split(":");
    String[] totalTime = total.split(":");
    
    int partTimeSeconds = Integer.parseInt(partTime[0]) * 3600 + Integer.parseInt(partTime[1]) * 60 + Integer.parseInt(partTime[2]);
    
    int totalTimeSeconds = Integer.parseInt(totalTime[0]) * 3600 + Integer.parseInt(totalTime[1]) * 60 + Integer.parseInt(totalTime[2]);
    
    int div = gcd(partTimeSeconds, totalTimeSeconds);
    
    return new int[]{(partTimeSeconds / div), (totalTimeSeconds/div)};
}