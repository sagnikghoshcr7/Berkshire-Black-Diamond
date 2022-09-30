double[] fareEstimator(int ride_time, int ride_distance, double[] cost_per_minute, double[] cost_per_mile) {
      
      double[] fares = new double[cost_per_minute.length];
      
      for(int i = 0; i < cost_per_minute.length; i++){
          fares[i] = cost_per_minute[i] * ride_time;
      }
      
      for(int i = 0; i < cost_per_minute.length; i++){
          fares[i] += cost_per_mile[i] * ride_distance;
      }
    
    return fares;    
}
