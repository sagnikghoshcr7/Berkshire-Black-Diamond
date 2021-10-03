/*

Problem:Jump Game II
Link:https://leetcode.com/problems/jump-game-ii/



*/

class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        int end = 0;
        
        int maxsofar = 0;
        int steps = 0;
        for(int i=0; end<n-1 ; end = maxsofar){
            steps++;
            while(i<=end){
                maxsofar = max(maxsofar,i+v[i]);
                i++;
            }
            
            if(maxsofar<=end) {
                
                return -1;
            }
            
        }
        return steps;
    }
};