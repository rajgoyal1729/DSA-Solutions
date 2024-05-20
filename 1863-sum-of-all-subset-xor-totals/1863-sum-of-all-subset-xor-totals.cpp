class Solution {
public:
    int f(vector<int>&v)
    {
        if(v.size()==0) return 0;
        int ans=v[0];
        for(int i=1;i<v.size();i++)
        {
            ans^=v[i];
        }
        return ans;

    }
    int subsetXORSum(vector<int>& nums) {
        int size=nums.size();
        int ans=0;
        for(int i=0;i<(1<<size);i++)
        {
            vector<int>v;
            
            for(int j=0;j<size;j++)
            {
                if(i&(1<<j)) v.push_back(nums[j]);
            }
            ans+=f(v);
            
        }
        return ans;

    }
};