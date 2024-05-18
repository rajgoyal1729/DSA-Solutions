class Solution {
public:

    static bool comparator(string a,string b)
    {
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>array;
        for(int i=0;i<nums.size();i++)
        {
            array.push_back(to_string(nums[i]));
        }
        string ans="";
        sort(array.begin(),array.end(),comparator);
        
        for(auto it: array)
        ans+=it;
        if(ans[0]=='0')
        return "0";
        else return ans;

    }
};