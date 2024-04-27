class Solution {
public:
    int f(vector<vector<int>>&dp,int k,int n)
    {
        if(n==0 || n==1) return n;
        if(k==1) return n;
        if(dp[k][n]!=-1) return dp[k][n];
        int l=1,h=n;
        int ans=INT_MAX;
        int temp=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=f(dp,k-1,mid-1);
            int right=f(dp,k,n-mid);

            temp=1+max(left,right);
            if(left<right) l=mid+1;
            else h=mid-1;
            ans=min(ans,temp);
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return f(dp,k,n);
    }
};