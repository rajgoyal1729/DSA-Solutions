class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int idx=0;
        long long sum=0;
        long long ans=0;
        int size=nums.size();
        while(sum<n)
        {
            if(idx<size && nums[idx]<=sum+1)
            {
                sum+=nums[idx];
                idx++;
            }
            else
            {
                sum+=(sum+1);
                ans++;
            }
        }
        return ans;
    }
};