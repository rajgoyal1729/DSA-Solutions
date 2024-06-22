class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2) nums[i]=1;
            else nums[i]=0; 
        }
        map<int,int>mp;
        int ans=0;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.count(sum-k)) ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};