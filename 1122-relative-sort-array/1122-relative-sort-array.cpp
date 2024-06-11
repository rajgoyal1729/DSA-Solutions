class Solution {
public:
        
    vector<int> relativeSortArray(vector<int>& A1, vector<int>& A2) {
        /*vector<int>ans;
        vector<int>not_present;
        map<int,int>mp2;
        for(int i=0;i<arr2.size();i++)
        {
            mp2[arr2[i]]=i;
        }
        map<int,int>mp1;
        for(auto &i:arr1) mp1[i]++;
        for(int j=0;j<arr2.size();j++)
        {
            int count=mp1[arr2[j]];
            while(count--)
            {
                ans.push_back(arr2[j]);
            }

        }
        for(int i=0;i<arr1.size();i++)
        {
            if(mp2.find(arr1[i])==mp2.end())
            {
                not_present.push_back(arr1[i]);
            }
        }
        sort(not_present.begin(),not_present.end());
        for(int i=0;i<not_present.size();i++)
        {
            ans.push_back(not_present[i]);
        }
        return ans;*/
        map<int,int>mp;
        vector<int>ans;
        for(auto &i:A1) mp[i]++;
        
        for(int i=0;i<A2.size();i++)
        {
            while(mp[A2[i]]!=0)
            {
                ans.push_back(A2[i]);
                mp[A2[i]]--;
            }
        }
        
        for(auto &it :mp)
        {
            while(it.second--) ans.push_back(it.first);
        }
        return ans;
    }
};