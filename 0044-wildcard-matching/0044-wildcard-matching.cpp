class Solution {
public:
    bool f(vector<vector<int>>&dp,string &s, string &p,int i,int j){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0)
        {
            for(int k=0;k<=j;k++)
            {
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') 
        return dp[i][j]=f(dp,s,p,i-1,j-1);
        else if(p[j]=='*')
        {
            return dp[i][j]= f(dp,s,p,i,j-1) || f(dp,s,p,i-1,j);
        }
        else return false;


    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return f(dp,s,p,s.size()-1,p.size()-1);
    }
};