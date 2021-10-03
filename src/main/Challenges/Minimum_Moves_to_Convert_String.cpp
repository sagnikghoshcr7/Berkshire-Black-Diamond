/*
Question Link:
https://leetcode.com/problems/minimum-moves-to-convert-string/

*/

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int c=0;
        for(int i=0; i<n;i++){
            if(s[i]=='X'){
            
                    c++;
                   
                for(int j=i; j<min(n,i+3);j++){
                    s[j]='O';
                
   }         }
        }
        
        return c;
    }
};