class Solution {
public:
    bool f(vector<vector<int>>&dp,int i,vector<int>&nums,int sum)
    {
        if(sum==0) return true;
        if(i==0) return nums[i]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take=false;
        bool nottake=f(dp,i-1,nums,sum);
        if(nums[i]<=sum) take=f(dp,i-1,nums,sum-nums[i]);
        return dp[i][sum]=take || nottake;
    }
    bool isSubsetSum(vector<int>&nums,int sum)
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(dp,n-1,nums,sum);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &i:nums) sum+=i;
        if(sum%2) return false;
        //int n=nums.size();
        return isSubsetSum(nums,sum/2);
        

    }
};