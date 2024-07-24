class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
            string s=to_string(nums[i]);
            int x=0;
            for(char c:s)
            {
                x=x*10+(mapping[c-'0']);
            }
            v.push_back({x,i});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto &it:v)
        {
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};