class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        double totalCost= INT_MAX;
        double totalQ=0;
        vector<pair<double,int>>wTq;
        for(int i=0;i<n;i++)
        {
            wTq.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        sort(wTq.begin(),wTq.end());
        priority_queue<int>pq;
        for(auto &it: wTq)
        {
            pq.push(it.second);
            totalQ+=it.second;
            if(pq.size()>k)
            {
                totalQ-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                double x= it.first * totalQ;
                totalCost=min(totalCost,x);
            }

        }
        return totalCost;
    }
};