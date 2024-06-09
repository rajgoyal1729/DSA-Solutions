class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int prefixmod=0;
        mp[prefixmod]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            prefixmod=(prefixmod+nums[i] %k +k) %k;
            ans+=mp[prefixmod];
            mp[prefixmod]++;
        }
        return ans;
    }
};