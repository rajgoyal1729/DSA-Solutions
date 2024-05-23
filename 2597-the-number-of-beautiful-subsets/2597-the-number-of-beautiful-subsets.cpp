class Solution {
public:
    //int ans=0;
    int f(vector<int>&nums,int k,unordered_map<int,int>&freq,int i)
    {
        if(i==nums.size()) return 1;
        int count=f(nums,k,freq,i+1);
        if(freq[nums[i]-k]==0)
        {
            freq[nums[i]]++;
            count+=f(nums,k,freq,i+1);
            freq[nums[i]]--;

        }
        return count;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        if(nums.size()==1) return 1;
        unordered_map<int,int>freq; 
        sort(nums.begin(),nums.end());
        
        return f(nums,k,freq,0)-1;
    }
};