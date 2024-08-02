class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans=INT_MAX;
        int count=0;
        for(auto &it:nums) if(it==1) count++;

        int onesCount=nums[0];
        int end=0;
        for(int start=0;start<nums.size();start++)
        {
            if(start) onesCount-=nums[start-1];
            while(end-start+1<count)
            {
                end++;
                onesCount+=nums[end%nums.size()];
            }
            ans=min(ans,count-onesCount);
        }
        return ans;
    }
};