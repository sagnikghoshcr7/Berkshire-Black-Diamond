/*

Problem : Longest Palindromic Substring
Link:https://leetcode.com/problems/longest-palindromic-substring/

*/


class Solution {
public:
    string longestPalindrome(string s) {
     int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int l=1;l<=n; l++){
            for(int i=0; i<n; i++){
                int j = i+l-1;
                if(j>=n)continue;
                if(s[i]==s[j]){
                    dp[i][j] = l>=3?dp[i+1][j-1]:1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        

        
        for(int l=n; l>=1;l--){
            for(int i=0; i<n; i++){
              int j = i+l-1;
                if(j>=n)continue;
                if(dp[i][j]==1){
                    
                    string res = "";
                    for(int k=i; k<=j;k++){
                        res+=s[k];
                    }
                    
                    return res;
                }
            }
        }
        
        return "-1";
    }
};