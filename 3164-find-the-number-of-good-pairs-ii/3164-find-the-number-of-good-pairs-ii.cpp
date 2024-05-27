class Solution {
public:
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int>mp;
        for(auto &i:nums2)
        {
            mp[i*k]++;
        }
        long long ans=0;
        for(auto num:nums1)
        {
            for(int i=1;i<=sqrt(num);i++)
            {
                if(num%i==0)
                {
                    int flag=num/i;
                    if(mp.count(i))
                    {
                        ans+=mp[i];
                    }
                    if(flag!=i && mp.count(flag))
                    {
                        ans+=mp[flag];
                    }
                }
            }
        }
        return ans;
        
    }
};