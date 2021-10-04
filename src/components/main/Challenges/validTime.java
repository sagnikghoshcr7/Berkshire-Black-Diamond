boolean validTime(String time) {
    String[] hoursAndMinutes = time.split(":");
    int hours = Integer.parseInt(hoursAndMinutes[0]);
    int minutes = Integer.parseInt(hoursAndMinutes[1]);
    
    if(hours < 0 || hours > 23)
        return false;
    else if(minutes < 0 || minutes > 59)
        return false;
    else
        return true;
}