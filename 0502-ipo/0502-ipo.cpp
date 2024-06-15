class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>>v;
        int n=profits.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int i=0;
        while(k)
        {
            while(i<n && v[i][0]<=w)
            {
                pq.push(v[i][1]);
                i++;
            }
            if(pq.empty()) break;
            w+= pq.top();
            pq.pop();
            k--;
        }
        
    
    return w;
    }
};