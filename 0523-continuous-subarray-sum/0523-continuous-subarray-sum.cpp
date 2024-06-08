class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        if(nums.size()==2) return (nums[0]+nums[1])%k==0;    
        vector<int>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        } 
        map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<prefix.size();i++)
        {
            if(mp.find(prefix[i]%k)!=mp.end())
            {
                if(i-mp[prefix[i]%k]>=2) return true;
            }
            else mp[prefix[i]%k]=i;
        }
        return false;
    }
};