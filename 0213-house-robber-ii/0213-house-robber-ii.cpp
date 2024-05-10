class Solution {
public:
    int f(vector<int>&dp,int size,vector<int>&nums3)
    {
        if(size<0) return 0;
        if(size==0) return nums3[0];
        if(dp[size]!=-1) return dp[size];
        return dp[size] =max(f(dp,size-2,nums3)+nums3[size], f(dp,size-1,nums3));
    }
    int rob(vector<int>& nums) {
        vector<int>nums1;
        vector<int>nums2;
        int size=nums.size();
        if(size<2) return nums[0];
        for(int i=1;i<size;i++)
        nums1.push_back(nums[i]);
        
        for(int i=0;i<size-1;i++)
        nums2.push_back(nums[i]);
        
        vector<int>dp1(size,-1), dp2(size,-1);
        return max(f(dp1,size-2,nums1), f(dp2,size-2,nums2));
    }
};