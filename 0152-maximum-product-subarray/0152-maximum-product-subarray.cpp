# define ll long long
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       __int128 min_so_far=nums[0];
       __int128 max_so_far=nums[0];
       __int128 ans=nums[0];
       if(nums.size()==1) return nums[0];
       for(int i=1;i<nums.size();i++)
       {
        if(nums[i]<0) swap(min_so_far,max_so_far);
        max_so_far=max((__int128)nums[i],max_so_far*nums[i]);  
        min_so_far=min((__int128)nums[i],min_so_far*nums[i]);
        ans=max(ans,max_so_far);
       } 
       return ans;
    }
};