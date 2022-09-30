double companyBotStrategy(int[][] trainingData) {
    int cnt = 0, sum = 0;
    for(int[] values : trainingData){
        int score = values[0];
        int validity = values[1];
        
        if(validity == 1){
            sum += score;
            cnt += 1;
        }
    }
    
    if(sum == 0)
        return 0.0;
    else
        return sum / (cnt * 1.0);
}