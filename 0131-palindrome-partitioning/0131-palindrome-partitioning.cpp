class Solution {
public:
    bool isPal(string& s, int start, int end)
    {
        if(start>end) return false;
        while(start<=end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void solve(string s, vector<vector<string>>&ans, vector<string>&path,int index)
    {
        if(index==s.length())
        {
            ans.push_back(path);
            return ;
        }
        for(int i=0;i<s.length();i++)
        {
            if(isPal(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                solve(s,ans,path,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(s,ans,path,0);
        return ans;
    }
};