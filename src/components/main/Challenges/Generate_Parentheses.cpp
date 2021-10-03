/*

Problem :Generate Parentheses
Link:https://leetcode.com/problems/generate-parentheses/


*/


class Solution {
public:
    
    vector<string>v;
    void recur(int open,int close, int n,string s){
        
        if(open<close) return ;
        
        if(open==n && close==n) {
         
            v.push_back(s);
        }
         
        
        if(open<n){
        s+='(';
        recur(open+1,close,n,s);
        s.pop_back();
        }
       
        if(close<n){
        s+=')';
        recur(open,close+1,n,s);
        s.pop_back();
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        
        
        v.clear();
        string res = "";
        recur(0,0,n,res);
        
        
        return v;
        
    }
};