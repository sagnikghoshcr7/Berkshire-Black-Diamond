/*

Problem: Word Search
Link: https://leetcode.com/problems/word-search/


*/


class Solution {
public:
    
    bool is_valid(int i, int j, int n, int m){
        
        if(i<0||i>=n||j<0||j>=m)return false;
        
        return true;
    }
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    bool dfs(int idx, string s, vector<vector<char>>& v,int i,int j ,vector<vector<int>>&vis){
    int n = v.size();
        int m = v[0].size();
        if(idx==s.size())return true;
        if(i<0||i>=n||j<0||j>=m||vis[i][j])return false;
        if(v[i][j]==s[idx]){
            vis[i][j] = 1;
           
            for(int k=0;k<4;k++){
                int x = i+dx[k];
                int y = j+dy[k];
                
                    if(dfs(idx+1,s,v,x,y,vis))return true;
                
            }
        }
        vis[i][j] = 0;
    return false;
    
    }
    
    
    bool exist(vector<vector<char>>& v, string s) {
      
        int n = v.size();
        if(n==0)return false;
        int m = v[0].size();
        
        bool turu = false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<int>>vis(n,vector<int>(m,0));
                turu|=dfs(0,s,v,i,j,vis);
            }
        }
        
        return turu;
        
    }
};