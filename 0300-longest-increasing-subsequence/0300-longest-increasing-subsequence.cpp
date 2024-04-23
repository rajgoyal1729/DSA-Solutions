class Solution {
public:
    /*int f(vector<vector<int>>&dp,vector<int>&nums,int idx,int prev_idx,int n)
    {
        if(idx==n) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        int ans=0;
       
        if( prev_idx==-1 || nums[idx]>nums[prev_idx] )
        ans= 1+f(dp,nums,idx+1,idx,n);
         ans=max(ans,f(dp,nums,idx+1,prev_idx,n));
        return dp[idx][prev_idx+1]=ans;

    }*/
    int lengthOfLIS(vector<int>& nums) {
        // T.C. n**2,S.C. n**2
        /*int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(dp,nums,0,-1,n);*/

        //T.C. nlog(n)
        int n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
            temp.push_back(nums[i]);
            else
            {
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return temp.size();
    }
};