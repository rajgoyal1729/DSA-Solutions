class Solution {
public:
    int start=0,end=0,max_length=0;
    bool f(vector<vector<int>>&dp, string &s, int i,int j)
    {
        string ans;
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j] && f(dp,s,i+1,j-1))
        {
            if(max_length<=j-i)
            {
                start=i;
                end=j;
                max_length=j-i;
            }
            return dp[i][j]=1;
        }
        f(dp,s,i+1,j);
        f(dp,s,i,j-1);

        return dp[i][j]=0;
    }
    string longestPalindrome(string s) {
       int size=s.length();
       vector<vector<int>>dp(size+1,vector<int>(size,-1));
       f(dp,s,0,size-1);
       string ans;
       for(int i=start;i<=end;i++) ans+=s[i];
       return ans;

    }
};