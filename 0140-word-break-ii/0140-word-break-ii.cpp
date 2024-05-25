class Solution {
public:
    void f(string& s,unordered_set<string>&wordSet,string &curr, vector<string>&ans,int idx)
    {
        if(idx==s.length())
        {
            ans.push_back(curr);
            return ;
        }
        for(int i=idx+1;i<=s.length();i++)
        {
           string word=s.substr(idx,i-idx);
            if(wordSet.find(word)!=wordSet.end())
            {
                string sen=curr;
                if(!curr.empty()) curr+=" ";
                curr+=word;
                f(s,wordSet,curr,ans,i);
                curr=sen;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        vector<string>ans;
        string curr;
        f(s,wordSet,curr,ans,0);
        return ans;
    }
};