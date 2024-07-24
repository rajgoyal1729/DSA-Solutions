class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val) nums[i]=-1;
        }
        int i=0,j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=-1) 
            {
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};