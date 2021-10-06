int phoneCall(int min1, int min2_10, int min11, int s) {
    
    double duration = 0;
    
    if(s < min1)
        return 0;
        
    duration += 1;
    s -= min1;
    
    for(int i = 0; i < 9; i++){
        if(s <= 0)
            return (int)Math.floor(duration);
        else if(s < min2_10){
            duration += s / (min2_10 * 1.0);
            s = 0;
        }
        else{
            duration += 1;
            s -= min2_10;
        }
    }
    
    duration += s / (min11 * 1.0);
    
    return (int)Math.floor(duration);
    
}