class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        set<int>st;
        vector<int>nums;
        for(auto &i:arr)
        mp[i]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        while(!pq.empty())
        {
            int count=pq.top().first;
            while(count--)
            {
                nums.push_back(pq.top().second);
            }
            pq.pop();
        }
        int size=nums.size();
        for(int i=0;i<size-k;i++)
        {
            st.insert(nums[i]);
        }
        return st.size();
    }
};