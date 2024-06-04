class Solution {
public:
    int maximumGap(vector<int>& A) {
        priority_queue<int>pq;
    for(auto &i:A ) pq.push(i);
    if(A.size()<2) return 0;
    int ans=0;
    while(!pq.empty()&& pq.size()>1)
    {
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        ans=max(first-second,ans);
    }
    return ans;
    }
};