class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        priority_queue<long long>pq;
        
        for(auto &i:happiness)
        {
            pq.push(i);
        }
        for(int i=0;i<k;i++)
        {
            if(pq.top()-i>=0)ans+=pq.top()-i;
            pq.pop();
        }
        //cout<<ans;
        return ans;
    }
};