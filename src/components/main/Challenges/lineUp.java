int lineUp(String commands) {
    char[] arr = commands.toCharArray();
    int cnt = 0, same = 0;
    
     for(int i = 0; i < arr.length; i++){
        if(arr[i] == 'L' || arr[i] == 'R')
            cnt += 1; 
        if(arr[i] == 'A')
            cnt += 2;
        
        if(cnt % 2 == 0)    
            same += 1;
    }
    
    return same;
}