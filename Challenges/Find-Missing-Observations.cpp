/*
Problem name: Find Missing Observations
Problem Link: https://leetcode.com/problems/find-missing-observations/

*/
#define pb push_back
class Solution {
public:
    vector<int> missingRolls(vector<int>& v, int mean, int m) {
        int n  = v.size();
        int s = 0;
        for(int i=0; i<n;i++){
            s+=v[i];
        }
        int tot = mean*(n+m);
        int r = tot-s;
        vector<int>ans;
        int used = 0;
        if(r<m || r>6*m) return ans;
        for(int i=0; i<m;i++){
            ans.pb(r/m);
            used+=(r/m);
        }
        r = r-used;
        int i=0;
        while(r>0){
            ans[i] ++;
            r--;
            i++;
        }
        
        return ans;
    }
};