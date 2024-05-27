class Solution {
public:
    int count(vector<int>&nums,int i)
    {
        int cnt=0;
        for(auto &it:nums)
        {
            if(it>=i) cnt++;
        }
        return cnt;
    }
    int specialArray(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<=size;i++)
        {
            int cnt=count(nums,i);
            if(i==cnt) return i;
        }
        return -1;
    }
};