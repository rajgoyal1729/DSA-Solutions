# define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>primes={2,3,5};
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        pq.push(1);
        int ans;
        int count=0;
        while(!pq.empty() && count!=n)
        {
            ll top=pq.top();
            ans=pq.top();
            pq.pop();
            for(auto &p:primes) pq.push(p*top);
            while(  !pq.empty() && pq.top()==top ) pq.pop();
            count++;  
        }
        return ans;
    }
};