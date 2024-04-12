class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int s1=nums1.size();
        int s2=nums2.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        set<pair<int,int>>vis;
        pq.push({nums1[0]+nums2[0],0,0});
        vis.insert({0,0});
        vector<vector<int>>ans;
        while(k-- && !pq.empty())
        {
            auto top=pq.top();
            int r=top[1];
            int c=top[2];
            ans.push_back({nums1[r],nums2[c]});
            pq.pop();
            if(r<s1-1 && vis.find({r+1,c})==vis.end())
            {
                pq.push({nums1[r+1]+nums2[c],r+1,c});
                vis.insert({r+1,c});
            }
            if(c<s2-1 && vis.find({r,c+1})==vis.end())
            {
                pq.push({nums1[r]+nums2[c+1],r,c+1});
                vis.insert({r,c+1});
            }
        }
        return ans;
    }
};