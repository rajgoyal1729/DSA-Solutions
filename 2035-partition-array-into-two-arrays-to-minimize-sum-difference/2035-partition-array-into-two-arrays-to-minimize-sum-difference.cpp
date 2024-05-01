class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &i:nums) sum+=i;
        int N=n/2;
        vector<vector<int>>left(N+1),right(N+1);

        for(int mask=0;mask<(1<<N);mask++)
        {
            int idx=0,l_sum=0,r_sum=0;
            for(int i=0;i<N;i++)
            {
                if(mask & (1<<i))
                {
                    idx++;
                    l_sum+=nums[i];
                    r_sum+=nums[i+N];
                }
            }
            left[idx].push_back(l_sum);
            right[idx].push_back(r_sum);
        }
        for(int i=0;i<=N;i++)
        {
            sort(right[i].begin(),right[i].end());
        }

        int ans=min(abs(sum-2*left[N][0]),abs(sum-2*right[N][0]));

        for(int i=1;i<N;i++)
        {
            for(auto &a: left[i])
            {
                int x=(sum-2*a)/2;
                int rightidx=N-i;
                auto &v=right[rightidx];
                auto b= lower_bound(v.begin(),v.end(),x);
                if(b!=v.end()) ans=min(ans,abs(sum-2*(a+(*b))));
             }
        }
        return ans;

    }
};