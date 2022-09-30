boolean isAdmissibleOverpayment(double[] prices, String[] notes, double x) {
    double instore = 0, instacart = 0;
    for(int i = 0; i < notes.length; i++){
        String[] temp = notes[i].split(" ");
        
        if(temp[1].equals("higher")){
            double percentage = Double.parseDouble(temp[0].replaceAll("%", ""));
            instacart += prices[i];
            instore = ( prices[i]  * 100 / (100 - percentage)); 
        }
        if(temp[1].equals("lower")){
            double percentage = Double.parseDouble(temp[0].replaceAll("%", ""));
            instacart += prices[i];
            instore += ( prices[i]  * 100 / (100 - percentage));
        }
        System.out.println(instacart + " "+ instore);
    }
    
    return x >= instacart - instore;
}
