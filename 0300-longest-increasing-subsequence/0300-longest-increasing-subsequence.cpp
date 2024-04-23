class Solution {
public:
    int f(vector<vector<int>>&dp,vector<int>&nums,int idx,int prev_idx,int n)
    {
        if(idx==n) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        int ans=0;
       
        if( prev_idx==-1 || nums[idx]>nums[prev_idx] )
        ans= 1+f(dp,nums,idx+1,idx,n);
         ans=max(ans,f(dp,nums,idx+1,prev_idx,n));
        return dp[idx][prev_idx+1]=ans;

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(dp,nums,0,-1,n);
    }
};