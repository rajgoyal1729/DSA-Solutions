class Solution {
public:
        static bool comparator(pair<int,int>a, pair<int,int>b)
        {
            if(a.second==b.second)
            {
                return a.first>b.first;
            }
            return a.second<b.second;
        }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        for(auto &i:nums)
        mp[i]++;

        vector<pair<int,int>>v;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            v.push_back(make_pair(it->first , it->second));
        }
        sort(v.begin(),v.end(),comparator);
        for(int i=0;i<v.size();i++)
        {
            int count= v[i].second;
            while(count--)
            {
                ans.push_back(v[i].first);
            }
        }
       
        return ans;
    }

};

