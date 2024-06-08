class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>>mp;
        for(string &s:strs)
        {
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);

        }
        
        vector<vector<string>>ans;
        for(auto &entry :mp)
        {

            ans.push_back({entry.second});
        }
        return ans;
        
    }
};