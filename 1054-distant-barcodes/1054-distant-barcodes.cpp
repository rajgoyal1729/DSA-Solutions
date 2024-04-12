class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int>mp;
        for(auto &i:barcodes) mp[i]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(pq.size()>1)
        {
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            top1.first--;
            if(top1.first) pq.push({top1.first,top1.second});
            top2.first--;
            if(top2.first) pq.push({top2.first,top2.second});
            ans.push_back(top1.second);
            ans.push_back(top2.second);
        }
        if(pq.size()) ans.push_back(pq.top().second);
        return ans;
    }
};